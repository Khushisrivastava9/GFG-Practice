//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	long long dp[10][1005];
	int mat[4][3]={{1,2,3},
	               {4,5,6},
	               {7,8,9},
	               {-1,0,-1}};
	long long solve(int i,int j,int N){
	    if(N==1) return 1;
	    if(dp[mat[i][j]][N]!=-1){
	        return dp[mat[i][j]][N];
	    }
	    long long a=solve(i,j,N-1);
	    long long b,c,d,e;//all four directions
	    b=c=d=e=0;
	    if(i-1>=0 && mat[i-1][j]!=-1) b=solve(i-1,j,N-1);
	    if(i+1<4 && mat[i+1][j]!=-1) c=solve(i+1,j,N-1);
	    if(j-1>=0 && mat[i][j-1]!=-1) d=solve(i,j-1,N-1);
	    if(j+1<3 && mat[i][j+1]!=-1) e=solve(i,j+1,N-1);
	    return dp[mat[i][j]][N]=a+b+c+d+e;
	}
	
	long long getCount(int N)
	{
	    dp[10][N+1];
	    memset(dp,-1,sizeof(dp));
	    long long ans=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<3;j++){
		        if(mat[i][j]!=-1){
		            ans+=solve(i,j,N);
		        }
		    }
		}
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends