//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
      long long  sum=0,sum_curr=0;
        for(long long  i=0;i<n;i++) {sum+=a[i]; sum_curr+=(a[i]*i);}
        
        long long  max_sum_forward=sum_curr;
        for(long long  i=1;i<n;i++){
            long long  sum_forward=sum_curr+sum-(long long)n*((long long)a[n-i]);
            max_sum_forward=max(max_sum_forward,sum_forward);
            sum_curr=sum_forward;
        }
        
        return max_sum_forward;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends