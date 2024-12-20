//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
         vector<int> ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int startrow=0;
        int endrow=r-1;
        int startcol=0;
        int endcol=c-1;

        int cnt=0;
        int totalcnt=r*c;
        while(cnt<totalcnt){
            for(int j=startcol;j<=endcol && cnt<totalcnt;j++){
                ans.push_back(matrix[startrow][j]);
                cnt++;
            }
            startrow++;

            for(int i=startrow;i<=endrow && cnt<totalcnt;i++){
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;

            for(int j=endcol;j>=startcol && cnt<totalcnt;j--){
                ans.push_back(matrix[endrow][j]);
                cnt++;
            }
            endrow--;

            for(int i=endrow;i>=startrow && cnt<totalcnt;i--){
                ans.push_back(matrix[i][startcol]);
                cnt++;
            }
            startcol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends