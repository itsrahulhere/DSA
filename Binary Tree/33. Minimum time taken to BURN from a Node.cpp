//Problem: https://practice.geeksforgeeks.org/problems/burning-tree/1#

    int minTime(Node* root, int target) 
    {
        //storing parent in map & finding target Node
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(root);
        Node*targetNode;
        while(!q.empty()){
            Node *parent=q.front();
            q.pop();
            if(parent->data==target) 
                targetNode=parent;
            if(parent->left){
                mp[parent->left]=parent;
                q.push(parent->left);
            }
            if(parent->right){
                mp[parent->right]=parent;
                q.push(parent->right);
            }
        }
        
        //traverse from targetNode to whole tree
        int ans=0;
        unordered_map<Node*,bool>vis;
        
        q.push(targetNode);
        vis[targetNode]=1;
        
        while(!q.empty())
        {
            int size=q.size();
            int fl=0;
            for(int i=0; i<size; i++)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    fl=1;
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && !vis[curr->right]){
                    fl=1;
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(mp[curr] && !vis[mp[curr]]){
                    fl=1;
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                }
            }
            if(fl) ans++;
        }
        return ans;
    }