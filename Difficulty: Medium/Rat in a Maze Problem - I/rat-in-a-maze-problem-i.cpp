//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &m,int n){
        if((r>=0 && r<n) && (c>=0 && c<n) && m[r][c]==1 && vis[r][c]==0){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int r,int c,vector<vector<int>> &m,int n,string path,vector<vector<bool>> &vis,vector<string> &ans){
        //base case
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        vis[r][c]=1;
        if(issafe(r+1,c,vis,m,n)){
            solve(r+1,c,m,n,path+'D',vis,ans);
        }
        if(issafe(r,c-1,vis,m,n)){
            solve(r,c-1,m,n,path+'L',vis,ans);
        }
        if(issafe(r,c+1,vis,m,n)){
            solve(r,c+1,m,n,path+'R',vis,ans);
        }
        if(issafe(r-1,c,vis,m,n)){
            solve(r-1,c,m,n,path+'U',vis,ans);
        }
        vis[r][c]=0;
    }
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        int n=m.size();
        vector<string> ans;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        string temp="";
        if(m[0][0]==0){
            return ans;
        }
        solve(0,0,m,n,temp,vis,ans);
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends