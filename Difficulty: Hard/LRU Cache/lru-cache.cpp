//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
   private:
   unordered_map<int,list<pair<int,int>>::iterator> mp;
list<pair<int,int>> l;
int size;
public:
LRUCache(int cap)
{
    size = cap;
}
int get(int key)
{
    if(mp.find(key)!=mp.end()) 
    {
        auto it = mp[key];
        pair<int,int> p = *it;
        l.erase(mp[key]);
        l.push_front(p);
        mp[key] = l.begin();
        return (p.second);
    }
    return -1;
}
    
    //Function for storing key-value pair.
void put(int key, int value)
{
    if(mp.find(key)!=mp.end())
    {
        l.erase(mp[key]);
    }
    else
    {
        if(l.size() == size)
        {
            mp.erase(l.back().first);
            l.pop_back();
        }
    }
    l.push_front({key,value});
    mp[key] = l.begin();
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends