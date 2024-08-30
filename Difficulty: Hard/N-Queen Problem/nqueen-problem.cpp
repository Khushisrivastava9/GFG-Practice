//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool canPlace(vector<vector<int>>& board, int x, int y) 
    {
        int n = board.size();

        for (int i = 0; i < x; i++) 
        {
            if (board[i][y] == 1) return false;
        }

        int i = x, j = y;
        while (i >= 0 && j >= 0) 
        {
            if (board[i][j] == 1) return false;
            i--;
            j--;
        }

        i = x;
        j = y;
        while (i >= 0 && j < n) 
        {
            if (board[i][j] == 1) return false;
            i--;
            j++;
        }

        return true;
    }

    void nQueenHelper(vector<vector<int>>& board, int i, int n, vector<vector<int>>& solutions) 
    {
        if (i == n) 
        {
            vector<int> currentSolution;
            for (int row = 0; row < n; row++) 
            {
                for (int col = 0; col < n; col++) 
                {
                    if (board[row][col] == 1) 
                    {
                        currentSolution.push_back(col + 1); 
                    }
                }
            }
            solutions.push_back(currentSolution);
            return;
        }

        for (int j = 0; j < n; j++) 
        {
            if (canPlace(board, i, j)) 
            {
                board[i][j] = 1;
                nQueenHelper(board, i + 1, n, solutions);
                board[i][j] = 0; 
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> solutions;
        nQueenHelper(board, 0, n, solutions);
        return solutions;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends