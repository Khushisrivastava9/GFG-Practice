//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int n,int a, int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M) 
    {
        int n=M.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,n,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int validcandidate(s.top());
        //celebrity ki row 0 honi chahiye
        int zerocnt=0;
        for(int i=0;i<n;i++){
            if(M[validcandidate][i]==0){
                zerocnt++;
            }
        }
        if(zerocnt!=n){
            return -1;
        }
        //celebrity ki col except uska row 1 hona chahiye kyuki sare log celebrity ko jante honge
        int onecnt=0;
        for(int i=0;i<n;i++){
            if(M[i][validcandidate]==1){
                onecnt++;
            }
        }
        if(onecnt!=n-1){
            return -1;
        }
        return validcandidate;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends