//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* rev(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        while(curr){
            Node* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head=rev(head);
        Node* temp=head;
        while(temp){
            if(temp->data==9 && temp->next==NULL){
                temp->data=0;
                temp->next=new Node(1);
                temp=temp->next;
                break;
                
            }
            else if(temp->data==9){
                temp->data=0;
                temp=temp->next;
            }
            else{
                temp->data=temp->data+1;
                temp=temp->next;
                break;
            }
        }
        head=rev(head);
        return head;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends