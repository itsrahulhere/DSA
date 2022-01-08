//Problem: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

    void rV(Node*root,vector<int>&v, int level)
    {
        if(!root) return ;
        if(v.size()<level)v.push_back(root->data);
        rV(root->right,v,level+1);
        rV(root->left,v,level+1);
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>v;
       rV(root,v,1);
       return v;
    }