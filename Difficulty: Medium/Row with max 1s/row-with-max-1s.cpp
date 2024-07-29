//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
int cntofrows(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==1){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    if(ans==-1){
        return 0;
    }
    else{
        return (arr.size())-ans;
    }
    
}
	int rowWithMax1s(vector<vector<int> > arr) {
	    // code here
	    int n=arr.size();
	    int maxi=INT_MIN;
	    int res=-1;
	    for(int i=0;i<n;i++){
	        int count=cntofrows(arr[i]);
	        if(maxi<count && count!=0){
	            maxi=count;
	            res=i;
	        }
	    }
	    return res;
	}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends