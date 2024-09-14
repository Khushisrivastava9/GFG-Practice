//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n=arr.size();
        vector<int> pos;
	    vector<int> neg;
	    for(int i=0 ;i<n ;i++)
	    {
	        if(arr[i]<0){
	            neg.push_back(arr[i]);
	        }else{
	            pos.push_back(arr[i]);
	        }
	    }
	    int p=0,i=0,ne=0;
	    while(i<n){
	        if(p!=pos.size()){
	            arr[i++]=pos[p++];
	        }
	        if(ne!=neg.size()){
	            arr[i++]=neg[ne++];
	        }
	    }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends