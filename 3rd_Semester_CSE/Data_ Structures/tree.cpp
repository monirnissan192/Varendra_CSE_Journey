#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node *Left;
    Node *Right;

    // Constructor
    Node(int Value) {
        Data = Value;
        Left = NULL;
        Right = NULL;
    }
};

// Function to create a tree from user input
Node* CreateTree() {
    int Value;
    cout << "Enter value (-1 for NULL): ";
    cin >> Value;

    // Base case: if the user enters -1, it represents a NULL node
    if (Value == -1) {
        return NULL;
    }

    // Create a new node with the entered value
    Node *newNode = new Node(Value);

    // Recursively create the left and right subtrees
    cout << "Enter left child of " << Value << ":\n";
    newNode->Left = CreateTree();

    cout << "Enter right child of " << Value << ":\n";
    newNode->Right = CreateTree();

    return newNode;
}

// Preorder function
void Preorder(Node *Root) {
    if (Root != NULL) {
        cout << Root->Data << " ";
        Preorder(Root->Left);
        Preorder(Root->Right);
    }
}

int main() {
    cout << "Create the binary tree:" << endl;
    Node *Root = CreateTree();

    cout << "\nThis is Preorder Traversal:" << endl;
    Preorder(Root);

    return 0;
}
