// 匈牙利算法，做个了解吧
// 真出到这题就寄了

#include <vector>

using namespace std;

class Solution {
public:
    int n, m;
    std::vector<std::vector<int>> adjacent;  // 图的临接表
    std::vector<int> match; // match[i] = j, i和j 互相match
    std::vector<int> matchx;
    std::vector<bool> visited; 
    int boys_num = 0;
    int girls_num = 0;

    int maximumInvitations(vector<vector<int>>& grid) {
        boys_num = grid.size();
        girls_num = grid.size();
        adjacent.reserve(boys_num);
        adjacent.assign(boys_num, vector<int>());
        visited.reserve(girls_num);
        visited.assign(girls_num, false);
        match.reserve(girls_num);
        match.assign(girls_num, -1);
        matchx.reserve(boys_num);
        matchx.assign(boys_num, -1);
        build_graph(grid);
        return maxMatching();
    }
    
    bool dfs(int u) {
        for (int v: adjacent[u]) {
            // std::cout << "boy: " << u << " girl: " << v << std::endl;

            // visited.assign(girls_num, false);
            if (!visited[v]) {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v])) {
                    match[u] = v;
                    matchx[v] = u;
                    // std::cout << "match[" << v << "]" << u << std::endl;
                    return true;
                }
            }
        }
        return false;
    }

    int maxMatching() {
        int result = 0;
        // std::cout << "maxMatching" << std::endl;
        for (int i = 0; i < boys_num; i++) {
            if (matchx[i] == -1) {
                visited.assign(girls_num, false);
                if (dfs(i)) {
                    ++result;
                }
            }
            
        }
        return result;
    }

    void build_graph(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    adjacent[i].push_back(j);
                }
            }
        }
    }
};