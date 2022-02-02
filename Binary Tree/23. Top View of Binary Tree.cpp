//Problem: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        
        map<int,int>mp; //<hd,topVal>
        queue<pair<Node*,int>>q; //<node,hd>
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            
            Node* curr=p.first;
            int hd=p.second;
            
           // if(mp.find(hd)==mp.end()) mp[hd]=curr->data;
            
            if(curr->left) q.push({curr->left, hd-1});
            if(curr->right) q.push({curr->right, hd+1});
            mp.insert({hd,curr->data});
        }
        
        for(auto m: mp)
            ans.push_back(m.second);
        
        return ans;
    }
