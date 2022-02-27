//Problem: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
public:
    bool bipartiteDfs(int node, vector<int>adj[], vector<int>&color){
        if(color[node]==-1)
            color[node]=1;
        
        for(int it : adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!bipartiteDfs(it,adj,color))
                    return false;
            }   
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i=0; i<V; i++) {
	        if(color[i]==-1) {
	            if(!bipartiteDfs(i,adj,color)) return false;
	        }
	    }
	    return true;
	}

};