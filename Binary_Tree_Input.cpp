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
        Node *newLeft = NULL;
        Node *newRight = NULL;
        if(l != -1) newLeft = new Node(l);
        if(r != -1) newRight = new Node(r);
        f->left = newLeft;
        f->right = newRight;
        if(f->left) q.push(newLeft);
        if(f->right) q.push(newRight);
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