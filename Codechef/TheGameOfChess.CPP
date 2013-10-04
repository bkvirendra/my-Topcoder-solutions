#include <iostream>
#include<vector>

using namespace std;

int main() {
    unsigned long int T;
    cin >> T;

    vector<int> arr;

    for (int t = 0; t < T; ++t) {
        unsigned long int n; // players
        cin >> n;

        unsigned long int passes = 0; // no. of passes to be given

        while(1) {
            if (n <= 2) {
                break;
            }
            int temp_pass = 0; // number of passes in the current round
            if (n % 2 == 1) {
                // give passes
                temp_pass = n % 2;
                n = (n - temp_pass)/2;
                passes += temp_pass;
                n += temp_pass;
            } else {
                n = n/2;
            }
        }
        arr.push_back(passes);
    }

    for (int i=0; i<arr.size();i++) {
        cout << arr[i] << "\n";
    }

    return(0);
}
