//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		bool dp[N+1];
		dp[0]=false;
		dp[1]=true;
		for(int i=2;i<=N;i++){
		    if(i-1>=0 && dp[i-1]==false){
		        dp[i]=true;
		    }
		    else if(i-X>=0 && dp[i-X]==false ){
		        dp[i]=true;
		    }
		    else if(i-Y>=0 && dp[i-Y]==false){
		        dp[i]=true;
		    }
		    else{
		        dp[i]=false;
		    }
		}
		return dp[N];
	}

};
	


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends