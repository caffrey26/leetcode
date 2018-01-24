#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d): data(d), left(NULL), right(NULL){}
};

class Solution{
public:
       TreeNode* UpsideDownBinaryTree(TreeNode* root){
         TreeNode *parent = NULL, *cur = root, *rSibling=NULL;
           while(cur){
               TreeNode* l = cur->left;
               TreeNode* r = cur->right;
               
               cur->left = rSibling;
               cur->right = parent;
               
               parent = cur;
               rSibling = r;
               cur = l;
           }
           
           return parent;
       }
};

void printTree(TreeNode* root){
    queue<TreeNode*> q;
    if(root)
        q.push(root);
    
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->data<<"\t";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);
    TreeNode* l4 = new TreeNode(4);
    TreeNode* l5 = new TreeNode(5);
    root->left = l2;
    root->right = l3;
    l2->left = l4;
    l2->right = l5;
    printTree(root);
    
    Solution S;
    root = S.UpsideDownBinaryTree(root);
    printTree(root);
}