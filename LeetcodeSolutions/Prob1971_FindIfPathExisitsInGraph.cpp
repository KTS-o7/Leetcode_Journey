class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& graph, int curr, int dest, unordered_set<int>& visited)
    {
        if(curr == dest)
            return true;
        
        visited.insert(curr);
        for(int next:graph[curr])
        {
            if(visited.find(next) == visited.end())
                if( dfs(graph,next,dest,visited))
                    return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        return dfs(graph, source, destination, visited);
    }
};

// Time complexity: O(N + E)
// Space complexity: O(N + E)

// Logic explained :
// 1. Create a graph using the edges.
// 2. Perform a DFS from the source node to the destination node.
// 3. If the destination node is reached, return true.
// 4. If the destination node is not reached, return false.
// 5. If the destination node is not reachable from the source node, return false.