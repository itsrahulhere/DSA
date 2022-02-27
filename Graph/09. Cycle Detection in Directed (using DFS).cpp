//Problem: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

    bool isCyclicDfs(int node, vector<int> adj[], vector<int>&vis, vector<int>&visDfs){
        vis[node]=1;
        visDfs[node]=1;
        for(int it : adj[node]){
            if(!vis[it]){
                if(isCyclicDfs(it, adj, vis, visDfs)) return true;
            }
            else if(visDfs[it])
                return true;
        }
        visDfs[node]=0;
        return false;   
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>visDfs(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCyclicDfs(i, adj, vis, visDfs)) return true;
            }
        }
        return false;
    }