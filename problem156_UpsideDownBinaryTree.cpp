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
          //if the left child of root is not a leaf
          bool leftNull = true;
          TreeNode* ret;
          if(root && root->left && root->left->left){
              leftNull = false;
              ret = UpsideDownBinaryTree(root->left);
          }
          
          //change the l and r of left
          if(root && root->left){
              root->left->right = root;
              root->left->left = root->right;
              if(leftNull)
                  ret = root->left;
          }
          
          //root l and r to be NULLed
          if(root){
              root->left = NULL;
              root->right = NULL;
          }
          return ret;
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