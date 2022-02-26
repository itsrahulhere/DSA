// #version 1 - Source Given & Graph is Connected
//Problem: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/
    vector<int>bfsOfGraph(int V, vector<int> adj[]) //source given int the parameter
    {
	    vector<int> bfs; 
	    vector<int> vis(V, 0); // 0-based indexing
	    queue<int> q; 
	    q.push(0); //taking source=0
	    vis[0] = 1; 
	    while(!q.empty())
        {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) { //here auto = int
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    
	    return bfs; 
	}

// #version 2 - No Source Given and Graph may be disconnected
	vector<int>bfsOfGraph(int V, vector<int> adj[])
    {
	    vector<int> bfs; 
	    vector<int> vis(V+1, 0); // 1-based indexing
	    
		for(int i=1; i<=V; i++){
			if(!vis[i]){
				queue<int> q; 
				q.push(0); 
				vis[0] = 1; 
				while(!q.empty()){
					int node = q.front();
					q.pop(); 
					bfs.push_back(node); 
					
					for(auto it : adj[node]) {
						if(!vis[it]) {
							q.push(it); 
							vis[it] = 1; 
						}
					}
				}
			}
		}
	    return bfs; 
	}