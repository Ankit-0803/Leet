class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> graph;
        // Step 1: Build graph
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0/val});
        }
        vector<double> results;
        // Step 2: Answer queries using BFS
        for (auto& q : queries) {
            string X = q[0], Y = q[1];
            if (!graph.count(X) || !graph.count(Y)) {
                results.push_back(-1.0);
                continue;
            }
            if (X == Y) { // same variable
                results.push_back(1.0);
                continue;
            }
            // BFS queue: (current node, product so far)
            queue<pair<string,double>> qnodes;
            qnodes.push({X, 1.0});
            unordered_set<string> visited;
            visited.insert(X);
            double ans = -1.0;
            while (!qnodes.empty()) {
                auto [curr, val] = qnodes.front();
                qnodes.pop();
                if (curr == Y) {
                    ans = val;
                    break;
                }
                for (auto& neighbor : graph[curr]) {
                    string nextNode = neighbor.first;
                    double weight = neighbor.second;
                    if (!visited.count(nextNode)) {
                        visited.insert(nextNode);
                        qnodes.push({nextNode, val * weight});
                    }
                }
            }
            results.push_back(ans);
        }
        return results;
    }
};
