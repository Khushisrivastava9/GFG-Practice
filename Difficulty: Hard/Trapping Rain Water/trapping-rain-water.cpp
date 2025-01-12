//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        long long lmax=arr[0];
        long long rmax=arr[n-1];
        long long lpos=1;
        long long rpos=n-2;
        long long water=0;
        while(lpos<=rpos){
            if(arr[lpos]>=lmax){
                lmax=arr[lpos];
                lpos++;
            }
            else if(arr[rpos]>=rmax){
                rmax=arr[rpos];
                rpos--;
            }
            else if(lmax<=rmax && lmax>arr[lpos]){
                water+=lmax-arr[lpos];
                lpos++;
            }
            else{
                water+=rmax-arr[rpos];
                rpos--;
            }
        }
        return water;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends