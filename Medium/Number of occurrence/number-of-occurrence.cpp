//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int firstocc(int nums[],int target,int n){
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(nums[m]==target){
            ans=m;
            e=m-1;
        }else if(nums[m]>target){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return ans;
}
int lastocc(int nums[],int target,int n){
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(nums[m]==target){
            ans=m;
            s=m+1;
        }else if(nums[m]>target){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return ans;
}
	int count(int arr[], int n, int x) {
	    int f=firstocc(arr,x,n);
	    int l=lastocc(arr,x,n);
	    if(f==-1 || l==-1) return 0;
	    return l-f+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends