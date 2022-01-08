//Problem: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

    int res(Node* root , int & ans)
    {
        if(!root)return 0;
        
        int lh = res(root->left, ans);
        int rh = res(root->right, ans);

        ans = max(ans, 1+lh+rh);
        
        return 1 + max(lh,rh);
    }