//Problem: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void lV(Node*root,int level, vector<int>&v)
{
    if(!root)return;
    if(v.size()<level)
        v.push_back(root->data);
    lV(root->left, level+1, v);
    lV(root->right, level+1, v);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   lV(root,1,v);
   return v;
}