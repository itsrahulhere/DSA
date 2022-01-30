//Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

    // Iterative
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        int cnt = 0; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                // inorder.push_back(node->val);
                cnt++; 
                if(cnt == k) return node->val; 
                node = node->right; 
            }  
        }
        return -1;
    }


//Recursive
public:
    void kth(TreeNode* root, int & k, int & ans)
    {
        if(!root)return ;
        kth(root->left, k,ans);
        if(--k==0) ans=root->val; 
        kth(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int  k) {
        int ans=-1;
        kth(root,k,ans);
        return ans;
        
    }
};