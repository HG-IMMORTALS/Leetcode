class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back({b, i});
            graph[b].push_back({a, i});
        }
        
        vector<double> probabilities(n, 0.0);
        probabilities[start] = 1.0;
        
        queue<int> queue;
        queue.push(start);
        
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            
            for (pair<int, int>& neighbor : graph[current]) {
                int next = neighbor.first;
                int i = neighbor.second;
                double newProb = probabilities[current] * succProb[i];
                
                if (newProb > probabilities[next]) {
                    probabilities[next] = newProb;
                    queue.push(next);
                }
            }
        }
        
        return probabilities[end];
    }
};