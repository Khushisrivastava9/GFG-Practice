//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int countStudents(vector<int> &arr, int n, int pages) {
        int students = 1, pagesPerStudent = 0;
        for(int i = 0; i < n; i++) {
            if(pagesPerStudent + arr[i] <= pages) {
                pagesPerStudent += arr[i];
            } else {
                students++;
                pagesPerStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) {
            return -1;
        }

        int maxi = INT_MIN, sum = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }

        int low = maxi, high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(countStudents(arr, n, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends