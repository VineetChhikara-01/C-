#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *build(Node *root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Entering data left of " << root->data << endl;
    root->left = build(root->left);
    cout << "Entering data right of " << root->data << endl;
    root->right = build(root->right);

    return root;
}

// DFS
void dfs(Node *root){
    if(root==NULL){
        return;
    }
    
}

// BFS
void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void preorder(Node *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(Node *root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
    Node *root = NULL;
    root = build(root);
    cout<<"BFS ";
    bfs(root);
    cout<<endl<<"InOrder ";
    inorder(root);
    cout<<endl<<"PreOrder ";
    preorder(root);
    cout<<endl<<"PostOrder ";
    postorder(root);
}
// 5 4 3 2 -1 -1 3 -1 -1 5 -1 -1 4 -1 -1