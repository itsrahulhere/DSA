//Problem: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool isCycleDfs(int node, int prev, vector<int> adj[], vector<int>&vis){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]) {
                if(isCycleDfs(it, node, adj,vis)) return true;
            }
            else if(it!=prev)
                return true;
        }
        return false;
    }
   
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]){
                if(isCycleDfs(i,-1,adj,vis)) return true;
            }
        }   
        return false;
    }
};