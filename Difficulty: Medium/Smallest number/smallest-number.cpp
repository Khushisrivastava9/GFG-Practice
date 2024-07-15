//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string ans="";
        char arr[]={'0','1','2','3','4','5','6','7','8','9'};
        while(D){
            if(S>9){
                ans='9'+ans;
                S=S-9;
            }
            else if(S<=9 && D!=1){
                ans=arr[S-1]+ans;
                S=1;
            }
            else if(S<=9 && D==1){
                ans=arr[S]+ans;
                S=0;
            }
            else if(S==1 && D!=1){
                ans='0'+ans;
            }
            D--;
        }
        if(S!=0) return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends