//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long int mod=1e9+7;
    int Maximize(vector<int> a)
    {
        // Complete the function
        int n=a.size();
        sort(a.begin(),a.end());
        long long int maxsum=0;
        for(long long int i=0;i<n;i++){
            maxsum+=(a[i]*i)%mod;
        }
        return maxsum%mod;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends