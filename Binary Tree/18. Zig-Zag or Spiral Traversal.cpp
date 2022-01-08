//Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);

            for(int i=0;i<size;i++)
            {
                int index = (leftToRight) ? i : (size-1-i);
                TreeNode* curr= q.front();
                q.pop();
                row[index]=curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(row);
            leftToRight=!leftToRight;
        }
        
        return ans;
    }