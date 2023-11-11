class Graph {
public:
    vector<vector<pair<int, int>>> g;
    
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto e: edges) addEdge(e);
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int minPath = -1;
        queue<int> q;
        vector<int> vis(g.size(), INT_MAX);
        q.push(node1); vis[node1] = 0;
        while(q.size()){
            auto node = q.front(); q.pop();
            if(node == node2) minPath = vis[node];
            for(auto [n, c]: g[node]){
                if(vis[n] < vis[node] + c) continue;
                q.push(n);
                vis[n] = vis[node] + c;
            }
        }
        return minPath;
    }
}; 

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */