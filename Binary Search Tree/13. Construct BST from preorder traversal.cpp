//Problem: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* build(vector<int>&preorder, int & i, int bound)
    {
        if(preorder.size()==i || preorder[i]>bound ) return NULL;
        
        TreeNode * root = new TreeNode(preorder[i++]);
        
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        
        return root;
    }    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder, i, INT_MAX);
    }
};