//Problem: https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	void findTopoSortDfs(int node, vector<int>&vis, stack<int>&st, vector<int>adj[]){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            findTopoSortDfs(it, vis, st, adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(vis[i]==0){
	            findTopoSortDfs(i, vis, st, adj);
	        }
	    }
	    vector<int>topo;
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};