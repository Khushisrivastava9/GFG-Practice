//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int firstOcc(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans = m;
                e = m - 1;
            } else if (nums[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
    int lastOcc(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans = m;
                s = m + 1;
            } else if (nums[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int f = firstOcc(arr, target);
        int l = lastOcc(arr, target);
        if (f == -1 || l == -1) return 0;
        return l - f + 1;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends