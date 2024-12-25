//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int n, m;

    void makeZeroes(vector<vector<int>> &mat, int i, int j)
    {

        // base case
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return;
        }
        int trackj = j;
        int tracki = i;

        // for making the row as 0
        // col pr travel karo
        while (j < m)
        {
            mat[i][j] = 0;
            j++;
        }

        j = trackj;
        while (j >= 0)
        {
            mat[i][j] = 0;
            j--;
        }

        j = trackj;

        while (i < n)
        {
            mat[i][j] = 0;
            i++;
        }

        i = tracki;

        while (i >= 0)
        {
            mat[i][j] = 0;
            i--;
        }
    }
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> indices;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    indices.push_back({i, j});
                }
            }
        }

        for (vector<int> &vec : indices)
        {
            int i = vec[0];
            int j = vec[1];

            makeZeroes(mat, i, j);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends