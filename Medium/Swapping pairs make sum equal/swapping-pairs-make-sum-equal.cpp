//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  int check(int first[] , int second[] , int firstSize , int secondSize , int sum1 , int sum2){
        set<int> st;
        int diff = abs(sum1 - sum2)/2;
        for(int i = 0 ; i<firstSize ; i++){
            st.insert(first[i]);
        }
        for(int i = 0 ; i<secondSize ; i++){
            int ele = diff + second[i];
            if(st.find(ele) != st.end()){
                return 1;
            }
        }
        
        return -1;
    }
    int findSwapValues(int a[], int n, int b[], int m) {
         int sum1 = 0;
        for(int i = 0 ; i<n ; i++)
            sum1+=a[i];
            
        int sum2 = 0;
        for(int i = 0 ; i<m ; i++)
            sum2+=b[i];
        
        double temp =(double) abs(sum1 - sum2)/2;
        int diff = abs(sum1 - sum2)/2;
        double rest = temp - diff;
        if(rest>0)
            return -1;
            
        int ans = -1;
        if(sum1<sum2){
            ans = check(b , a , m , n , sum2 , sum1);
        }
        else{
            ans = check(a , b , n ,m , sum1 , sum2);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends