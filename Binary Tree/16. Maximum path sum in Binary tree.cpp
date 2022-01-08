//Problem: https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

//Function to return maximum path sum from any node in a tree.
    int PathSum(Node * node, int & ans)
    {
        if(!node) return 0;
        
        int left = max(0, PathSum(node->left, ans));
        int right = max(0, PathSum(node->right, ans));
        
        ans=max(ans,(left+right+(node->data)));
        
        return node->data + max(left,right);
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int ans=INT_MIN;
        PathSum(root,ans);
        return ans;
    }