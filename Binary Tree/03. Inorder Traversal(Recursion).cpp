// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

void in(TreeNode* root, vector<int>&ans)
{
    if(root!=NULL)
    {
        in(root->left,ans);
        ans.push_back(root->val);
        in(root->right,ans);
    }

    // // or can do as below
    // if(!root) return;
    // in(root->left,ans);
    // ans.push_back(root->val);
    // in(root->right,ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector <int>ans;
    
    in(root,ans);
    
    return ans;
}