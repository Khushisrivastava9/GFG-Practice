//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        vector <int> ans;
            int n=txt.size();
            int m=pat.size();
            for(int i=0;i<n;i++){
                if(pat[0]==txt[i] && pat==txt.substr(i,m)){
                    ans.push_back(i);
                }
            }
            if(ans.empty()){
                return {};
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends