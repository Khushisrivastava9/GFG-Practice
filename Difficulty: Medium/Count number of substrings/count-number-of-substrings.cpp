//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long int atmostk(string s,int k){
    int l=0,r=0,cnt=0;//left pointer ,right pointer and cnt stores no of characters
    long long int ans=0;//to store final ans
    vector<int> v(26,0);//vector bnado jisme frq store krenge,map ni leerhe coz tc tle dega
    while(r<s.length()){
        v[s[r]-'a']++;
        if(v[s[r]-'a']==1) cnt++;
        while(cnt>k){
            v[s[l]-'a']--;
            if(v[s[l]-'a']<=0) cnt--;
            l++;
        }
        ans+=r-l+1;
        r++;
    }
    return ans;
    
    
  }
    long long int substrCount (string s, int k) {
    	return atmostk(s,k)-atmostk(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends