// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

vector<int> preorderTraversal(TreeNode* root) {
    vector <int>ans;
    if(!root) return ans;
    stack<TreeNode*> s;
    s.push(root);
     
    while(!s.empty())
    {
        int size=s.size();
        for(int i=0; i<size;i++)
        {  
            TreeNode* curr=s.top();
            s.pop();
            ans.push_back(curr->val);
            if(curr->left)s.push(curr->left);
            if(curr->right)s.push(curr->right);
        } 
    }
    return ans;
}