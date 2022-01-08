//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(true)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                if(st.empty()==true) break;
                curr=st.top();
                st.pop();
                v.push_back(curr->val);
                curr=curr->right;
            }
        }
        return v;
    }