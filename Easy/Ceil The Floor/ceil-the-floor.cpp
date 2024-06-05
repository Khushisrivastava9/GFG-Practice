//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    int f=-1,c=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>x){
            c=arr[mid];
            e=mid-1;
        }else if(arr[mid]==x){
            f=c=arr[mid];
            break;
        }else{
            f=arr[mid];
            s=mid+1;
        }
    }
    return  {f,c};
}