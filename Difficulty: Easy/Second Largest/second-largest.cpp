//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
         int firstlarg=INT_MIN;
	    int secondlarg=firstlarg;
	    int i=0;
	    while(i<n){
	        if(firstlarg<arr[i]){
	            secondlarg=firstlarg;
	            firstlarg=arr[i];
	        }else if(secondlarg<arr[i]  && arr[i] != firstlarg){
	            secondlarg=arr[i];
	        }
	        i++;
	    }
	    return secondlarg==INT_MIN?-1:secondlarg;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends