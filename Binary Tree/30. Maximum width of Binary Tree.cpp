//Problem: https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

    int getMaxWidth(Node* root) {
        queue<Node*>q;
        int ans=INT_MIN;
        
        if(!root) return 0;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            ans=max(ans,size);
            for(int i=0;i<size;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }  
        return ans;
    }