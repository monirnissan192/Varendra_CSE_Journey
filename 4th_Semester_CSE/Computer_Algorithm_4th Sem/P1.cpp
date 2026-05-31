#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x, element;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x;
        map<int, int> tally;
        int max_freq = 0;

        for (int j = 0; j < x; j++) {
            cin >> element;
            tally[element]++;

            if (tally[element] > max_freq) {
                max_freq = tally[element];
            }
        }

        cout << max_freq << "\n";
    }

    return 0;
}
