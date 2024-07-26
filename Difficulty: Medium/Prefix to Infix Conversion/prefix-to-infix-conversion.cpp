//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        int n=pre_exp.size();
        for(int i=n-1;i>=0;i--){
            char e=pre_exp[i];
            if(e>='A' && e<='Z' || e>='a' && e<='z' || e>='0' && e<='9'){
                st.push(string(1,e));
            }
            else{
                string firsttop=st.top();
                st.pop();
                string sectop=st.top();
                st.pop();
                string temp='('+firsttop+e+sectop+')';
                st.push(temp);
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends