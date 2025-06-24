// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        int j=k;
        int i=0,n=arr.size();
        while(i<n && j--){
            pq.push(arr[i]);
            i++;
        }
        while(i<n){
            if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            i++;
        }
        return pq.top();
    }
};