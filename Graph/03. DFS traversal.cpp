// #version 1 - Source Given & Graph is Connected
//Problem: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& storeDfs)
    {
        storeDfs.push_back(node);
        vis[node]=1; 
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,storeDfs);
            }
        }    
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> storeDfs;
        dfs(0, adj, vis, storeDfs);
        return storeDfs;
    }
};

// #version 2 - No Source Given and Graph may be disconnected
class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& storeDfs)
    {
        storeDfs.push_back(node);
        vis[node]=1; 
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,storeDfs);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0); // 1-based indexing
        vector<int> storeDfs;
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, storeDfs);
            }
        }
        return storeDfs;
    }
};