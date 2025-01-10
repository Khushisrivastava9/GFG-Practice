//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
         vector<int> ans;
        int n=arr.size();
        int i=0;
        int j=0;
        if(k>n)
        return ans;
        map<int,int> mp;
       
        while(j<k){
            mp[arr[j]]++;
            j++;
        }
        
         ans.push_back(mp.size());
        while(j<n){
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            mp.erase(arr[i]);
            mp[arr[j]]++;
            j++;
            i++;
            ans.push_back(mp.size());
        }
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends