// Problem: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
    TreeNode* build(vector<int> inorder, int is, int ie, vector<int>postorder, int ps, int pe, unordered_map<int,int>&map)
    {
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root=new TreeNode(postorder[pe]);
        
        int inroot=map[postorder[pe]];
        int leftNodes=inroot-is;
        
        root->left = build(inorder, is, inroot-1, postorder, ps, ps+leftNodes-1, map);
        root->right = build(inorder, inroot+1, ie, postorder, ps+leftNodes, pe-1, map);
        
        return root;
    }
    
    
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>map;
        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, map);
    }
};