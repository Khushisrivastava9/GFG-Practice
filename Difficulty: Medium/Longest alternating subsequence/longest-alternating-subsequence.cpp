//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
	public:
		int alternatingMaxLength(vector<int>&nums){
		     int n=1,m=1;
           
            for(int i=1;i<nums.size();i++){
              
                   if(nums[i]>nums[i-1])
                    {
                       n=m+1;
                     }
                  else if(nums[i]<nums[i-1])
                    {
                      m=n+1;
                   }
               
                 else 
                   {
                     continue;
                   }
           }
           return max(m,n);
		}
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends