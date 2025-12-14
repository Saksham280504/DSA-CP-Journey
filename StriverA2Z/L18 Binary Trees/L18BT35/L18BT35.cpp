#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    public:
    string serialize(Node* root) {
        if(!root) return "";
        string s = "";
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node==nullptr) s += "#,"; // This means that in the queue there will be nullpointer nodes as well
            else s.append(to_string(node->data)+',');
            if(node!=nullptr) { // This makes sure that if we encounter a nullnode, we stop right there, and do not perform a runtime error
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    Node* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data); // This will convert the string into a series of string
        string str; // This will hold the value of nodes
        getline(s,str,','); // Whenever this function is called we will move from one node value in string to another which are seperated by a ','
        Node* root = new Node(stoi(str));
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            // left-child
            getline(s,str,',');
            if(str=="#") {
                node->left = nullptr;
            }
            else {
                node->left = new Node(stoi(str));
                q.push(node->left);
            }
            
            // right-child
            getline(s,str,',');
            if(str=="#") {
                node->right = nullptr;
            }
            else {
                node->right = new Node(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
