//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        int maxlen=0, sum=0;
        int i=0;
        unordered_map<int,int>mp;
        while(i<n){
            sum+=arr[i]==1?1:-1;
            if(sum==0){
                maxlen=i+1;
            }
            
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen, i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
            
            i++;
            
        }
        
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends