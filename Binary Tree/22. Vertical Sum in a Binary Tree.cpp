//Problem: https://practice.geeksforgeeks.org/problems/vertical-sum/1

    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int>ans;
        map<int,int>mp; // <hd,sum>
        queue<pair<Node*,int>>q; // <node,hd>
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int hd=p.second;
            Node* curr=p.first;
            
            mp[hd]+=curr->data;
            
            if(curr->left)q.push({curr->left, hd-1});
            if(curr->right)q.push({curr->right, hd+1});
        }
        
        for(auto m:mp)
        {
            ans.push_back(m.second);
        }
        
        return ans;
    }