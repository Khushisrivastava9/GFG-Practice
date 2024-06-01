//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        unordered_map<char,int> m;
        for(auto it:s){
            m[it]++;
        }
        int y=0;
        for(char ch='a';ch<='y';ch+=2){
            if(m[ch]!=0 && m[ch]%2==1) y++;
        }
        int x=0;
        for(char ch='b';ch<='z';ch+=2){
            if(m[ch]!=0 && m[ch]%2==0) y++;
        }
        int ans = x+y;
        if(ans%2) return "ODD";
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends