//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// int rec(vector<vector<int>> mat,int i,int j,int &maxi){
//     int ans;
//     if(i>=mat.size() || j>=mat[0].size()){
//         return 0;
//     }
//     int right=rec(mat,i,j+1,maxi);
//     int diagonal=rec(mat,i+1,j+1,maxi);
//     int down=rec(mat,i+1,j,maxi);
//     if(mat[i][j]==1){
//         ans=1+min(right,min(diagonal,down));
//         maxi=max(maxi,ans);
//         return ans;
        
//     }
//     else{
//         return 0;
//     }
// }
// int recmem(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
//     int ans;
//     if(i>=mat.size() || j>=mat[0].size()){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int right=recmem(mat,i,j+1,maxi,dp);
//     int diagonal=recmem(mat,i+1,j+1,maxi,dp);
//     int down=recmem(mat,i+1,j,maxi,dp);
//     if(mat[i][j]==1){
//         ans=1+min(right,min(diagonal,down));
//         dp[i][j]=ans;
//         maxi=max(maxi,dp[i][j]);
//         return dp[i][j];
        
//     }
//     else{
//         return dp[i][j]=0;
//     }
// }

// int tab(vector<vector<int>> &mat,int &maxi){
//     int row=mat.size();
//     int col=mat[0].size();
//     vector<vector<int>> dp(row+1,vector<int> (col+1,0));
    
//     for(int i=row-1;i>=0;i--){
//         for(int j=col-1;j>=0;j--){
//             int right=dp[i][j+1];
//             int diagonal=dp[i+1][j+1];
//             int down=dp[i+1][j];
//             if(mat[i][j]==1){
//                 dp[i][j]=1+min(right,min(diagonal,down));
//                 maxi=max(maxi,dp[i][j]);
        
//             }
//             else{
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return dp[0][0];
// }

int spaceopt(vector<vector<int>> &mat,int &maxi){
    int row=mat.size();
    int col=mat[0].size();
    vector<int> curr(col+1,0);
    vector<int> next(col+1,0);
    
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=curr[j+1];
            int diagonal=next[j+1];
            int down=next[j];
            if(mat[i][j]==1){
                curr[j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,curr[j]);
        
            }
            else{
                curr[j]=0;
            }
        }
        next=curr;
    }
    return next[0];
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        //rec
        
        // int maxi=0;
        // rec(mat,0,0,maxi);
        // return maxi;
        
        //rec+mem
        
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // int maxi=0;
        // recmem(mat,0,0,maxi,dp);
        // return maxi;
        
        //tab
        
        // int maxi=0;
        // tab(mat,maxi);
        // return maxi;
        
        //space opt
        int maxi=0;
        spaceopt(mat,maxi);
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends