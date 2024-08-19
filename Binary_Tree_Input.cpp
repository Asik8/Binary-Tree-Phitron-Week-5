#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    ll data;
    Node *left;
    Node *right;

    Node(ll data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node * Input_Tree() 
{
    int n;
    cin>>n;
    Node * root;
    if(n != -1) root = new Node(n);
    else root = NULL;
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node *f = q.front();
        q.pop(); 
        int l,r;
        cin>>l>>r;
        Node *left = NULL;
        Node *right = NULL;
        if(l != -1) left = new Node(l);
        if(r != -1) right = new Node(r);
        f->left = left;
        f->right = right;
        if(f->left) q.push(left);
        if(f->right) q.push(right);
    }
    return root;
}

void Print_LevelOrder(Node *root) 
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = Input_Tree();
    Print_LevelOrder(root);
    return 0;
}