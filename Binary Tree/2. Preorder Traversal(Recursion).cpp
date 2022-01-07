void pre(TreeNode* root, vector<int>&ans)
{
    if(root!=NULL)
    {
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);
    }

    // // or can do as below
    // if(!root) return;
    // ans.push_back(root->val);
    // pre(root->left,ans);
    // pre(root->right,ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector <int>ans;
    
    pre(root,ans);
    
    return ans;
}