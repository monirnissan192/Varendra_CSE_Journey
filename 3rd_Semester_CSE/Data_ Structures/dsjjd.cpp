#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* Left;
    Node* Right;
    Node(int value) {
        Data = value;
        Left = NULL;
        Right = NULL;
    }
};

Node* Insert(Node* Root, int Value) {
    if (Root == NULL) {
        return new Node(Value);
    }
    if (Value < Root->Data) {
        Root->Left = Insert(Root->Left, Value);
    } else {
        Root->Right = Insert(Root->Right, Value);
    }
    return Root; // Add this return statement to ensure proper updates.
}

void Search(Node* Root, int Value) {
    while (Root != NULL) {
        if (Value == Root->Data) {
            cout << "Value: " << Value << " Found" << endl;
            return;
        } else if (Value < Root->Data) {
            Root = Root->Left; // Correct direction for smaller values.
        } else {
            Root = Root->Right; // Correct direction for larger values.
        }
    }
    cout << "Value: " << Value << " Not Found" << endl; // Only print once, after the loop.
}

void Inorder(Node* Root) {
    if (Root != NULL) {
        Inorder(Root->Left);
        cout << Root->Data << " ";
        Inorder(Root->Right);
    }
}

void Preorder(Node* Root) {
    if (Root != NULL) {
        cout << Root->Data << " ";
        Preorder(Root->Left);
        Preorder(Root->Right);
    }
}

void Postorder(Node* Root) {
    if (Root != NULL) {
        Postorder(Root->Left);
        Postorder(Root->Right);
        cout << Root->Data << " ";
    }
}

int main() {
    int n, Value;
    Node* Root = NULL;

    cout << "Enter the number of elements in the Tree: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> Value;
        Root = Insert(Root, Value);
    }

    cout << "Inorder Traversal is: ";
    Inorder(Root);
    cout << endl;

    cout << "Preorder Traversal is: ";
    Preorder(Root);
    cout << endl;

    cout << "Postorder Traversal is: ";
    Postorder(Root);
    cout << endl;

    cout << "Enter the Search Element: ";
    cin >> Value;
    Search(Root, Value); // Call the Search function here.

    return 0;
}
