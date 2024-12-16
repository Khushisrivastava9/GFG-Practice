//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    int idx = 0;

    // Traverse both arrays
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            idx++;
            if (idx == k) {
                return a[i];
            }
            i++;
        } else {
            idx++;
            if (idx == k) {
                return b[j];
            }
            j++;
        }
    }

    // Traverse remaining elements in 'a'
    while (i < n) {
        idx++;
        if (idx == k) {
            return a[i];
        }
        i++;
    }

    // Traverse remaining elements in 'b'
    while (j < m) {
        idx++;
        if (idx == k) {
            return b[j];
        }
        j++;
    }

    return -1; // Default case, should not occur for valid input
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends