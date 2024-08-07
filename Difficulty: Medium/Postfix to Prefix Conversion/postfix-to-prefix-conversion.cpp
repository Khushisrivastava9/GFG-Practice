//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        int n=post_exp.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            char e=post_exp[i];
            if(e>='a' && e<='z' || e>='A' && e<='Z' || e>='0' && e<='9'){
                st.push(string(1,e));
            }
            else{
                string firsttop=st.top();
                st.pop();
                string sectop=st.top();
                st.pop();
                string tmp=e+sectop+firsttop;
                st.push(tmp);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends