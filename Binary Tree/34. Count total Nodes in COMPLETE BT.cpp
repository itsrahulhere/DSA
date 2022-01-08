//Problem: https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
    
//     int leftHeight(TreeNode* root)
//     {
//         int count=0;
//         while(root)
//         {
//             count++;
//             root=root->left;
//         }
//         return count;
//     }
//     int rightHeight(TreeNode* root)
//     {
//         int count=0;
//         while(root)
//         {
//             count++;
//             root=root->right;
//         }
//         return count;
//     }
    
    
    
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = 0, rh = 0;
        TreeNode* l=root;
        TreeNode* r=root;
        
        while(l){lh++; l=l->left;}
        while(r){rh++; r=r->right;}
        
        if(lh==rh) return ((1<<lh)-1); 
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};