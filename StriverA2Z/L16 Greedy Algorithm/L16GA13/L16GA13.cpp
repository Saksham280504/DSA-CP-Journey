
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Doubly Linkedlist
class Node {
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = prev = nullptr;
    }
};


class LRUCache {
    public:
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    int cap;
    map<int, Node*> hash;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    } 

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int _key) {
        if(hash.find(_key)!=hash.end()) {
            Node* node = hash[_key];
            int nodeVal = node->val;
            hash.erase(_key);
            deleteNode(node);
            addNode(node);
            hash[_key] = node;
            return nodeVal;
        }
        return -1;
    }

    void put(int _key, int _val) {
        if(hash.find(_key)!=hash.end()) {
            Node* node = hash[_key];
            deleteNode(node);
            hash.erase(_key);
        }

        if(hash.size()==cap) {
            Node* node = tail->prev;
            int tailKey = node->key;
            hash.erase(tailKey);
            deleteNode(node);
        }

        addNode(new Node(_key,_val));
        hash[_key] = head->next;
    }

    // TC -> O(1) (for both get and put operations)
};

int32_t main() {
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