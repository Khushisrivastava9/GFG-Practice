//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int priority(char ele){
      if(ele=='+' || ele=='-') return 1;
      else if(ele=='*' || ele=='/') return 2;
      else if(ele=='^') return 3;
      else return 0;
  }
    string infixToPostfix(string s) {
        stack<char> st;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            char e=s[i];
            if(e>='A' && e<='Z' || e>='a' && e<='z' || e>='0' && e<='9'){
                ans+=e;
            }
            else if(e=='(') st.push('(');
            else if(e==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
            }
            else{
                while(!st.empty() && priority(e)<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(e);
                
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends