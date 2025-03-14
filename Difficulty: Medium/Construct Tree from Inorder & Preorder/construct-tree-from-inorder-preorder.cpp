//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  int findposition(int ele,vector<int> &inorder,int inordstart,int inordend){
        for(int i=inordstart;i<=inordend;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> &inorder,vector<int> &preorder,int &index,int inordstart,int inordend, int n){
        //base case
        if(index>=n || inordstart>inordend){
            return NULL;
        }
        int ele=preorder[index++];
        Node* root= new Node(ele);
        int posn=findposition(ele,inorder,inordstart,inordend);
        //recursive calls
        root->left=solve(inorder,preorder,index,inordstart,posn-1,n);
        root->right=solve(inorder,preorder,index,posn+1,inordend,n);
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preindex=0;
        int n=inorder.size();
        Node* ans=solve(inorder,preorder,preindex,0,n-1,n);
        return ans;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends