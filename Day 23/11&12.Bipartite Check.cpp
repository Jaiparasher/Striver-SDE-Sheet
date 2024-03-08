class Solution {
public:
    bool checkBfs(int i, int color[], vector<vector<int>>& graph) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                } else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }
    bool checkDfs(int node, int col, int color[], vector<vector<int>>& graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if(checkDfs(it,!col,color,graph)==false) return false;
            } else if (color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for (int i = 0; i < n; i++)
            color[i] = -1;
        // for (int i = 0; i < n; i++) {
        //     if (color[i] == -1) {
        //         if (checkbfs(i, color, graph) == false)
        //             return false;
        //     }
        // }
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (checkDfs(i,0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};