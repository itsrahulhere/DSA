//Problem: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,vector<int>>mp; // <hd,nodeVal>
        queue<pair<Node*,int>>q; // <node,hd>
        
        q.push({root,0});

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            Node*curr=p.first;
            int hd=p.second;
        
            mp[hd].push_back(curr->data);
            
            if(curr->left) q.push({curr->left, hd-1});
            if(curr->right) q.push({curr->right, hd+1});
            
        }
        
        for(auto m: mp){
            for(auto s:m.second)
                ans.push_back(s);
        }
        
        return ans;
    }