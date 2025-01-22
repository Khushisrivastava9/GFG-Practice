//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node * prev = nullptr;
        while(num1){
            Node * temp = num1->next;
            num1->next = prev;
            prev = num1;
            num1 = temp;
        }
        num1 = prev;
        prev = nullptr;
        while(num2){
            Node * temp = num2->next;
            num2->next = prev;
            prev = num2;
            num2 = temp;
        }
        num2 = prev;
        int sum = num1->data+num2->data;
        Node * ans = new Node (sum%10);
        int carry = (sum =sum/10);
        num1 = num1->next;
        num2 = num2->next;
        ans ->next = nullptr;
        prev = ans;
        
        
        while(num1 and num2){
            
            sum = num1->data + num2->data + carry;
            Node * newNode = new Node(sum%10);
            carry = (sum=sum/10);
            newNode ->next = prev;
            prev = newNode ;
            num1= num1->next;
            num2 = num2->next;
        }
        while(num1){
            int sum = num1->data + carry;
            Node * newNode = new Node (sum%10);
            carry = (sum=sum/10);
            newNode ->next = prev;
            prev = newNode;
            num1 = num1->next;
        }
        while(num2){
            int sum = num2->data + carry;
            Node * newNode = new Node (sum%10);
            carry = (sum=sum/10);
            newNode ->next = prev;
            prev = newNode;
            num2= num2->next;
        }
        while(carry !=0){
            Node * newNode = new Node (carry%10);
            newNode->next = prev;
            prev = newNode;
            carry = carry/10;
        }
        while(prev and prev->data == 0){
            if(!prev->next) break;
            prev = prev ->next;
        }
        
        return prev;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends