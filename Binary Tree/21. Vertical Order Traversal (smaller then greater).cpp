//Problem: 

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // vertical, <level, overlaping>  (0,2,{6,6})
        queue<pair<TreeNode*, pair<int, int>>> todo; // nodes, <vertical, level>
        
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int vertical = p.second.first, level = p.second.second;
            nodes[vertical][level].insert(node -> val);
            
            if(node -> left) 
                todo.push({node -> left, {vertical - 1, level + 1}});
            
            if(node -> right)
                todo.push({node -> right, {vertical + 1, level + 1}});
            
        }
        
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};