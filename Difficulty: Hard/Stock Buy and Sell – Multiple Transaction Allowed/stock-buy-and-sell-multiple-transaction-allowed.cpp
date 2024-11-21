//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
         int maxProfit = 0;
        int s = 0;
        int e = 0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i] >= prices[e]){
                e = i;
            }else{
                maxProfit += prices[e] - prices[s];
                s = i;
                e = i;
            }
        }
        maxProfit += prices[e] - prices[s];
        return maxProfit;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends