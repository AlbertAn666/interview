#include <vector>

using namespace std;

class UnionFind {
public:
    int count;
    vector<int> parent;

    UnionFind(int n) {
        count = n;
        parent = vector<int>(n, 0);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int _find(int a) {
        if (a != parent[a]) {
            parent[a] = _find(parent[a]);
        }
        return parent[a];
    }


    void _union(int a, int b) {
        int ra = _find(a);
        int rb = _find(b);
        if (ra == rb) {
            return;
        }
        parent[ra] = rb;
        count--;
    }
};

struct cmp {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), cmp());
        UnionFind uf(n);
        for (auto& log: logs) {
            int a = log[1];
            int b = log[2];
            // std::cout << uf.count << std::endl;
            uf._union(a, b);
            if (uf.count == 1) {
                return log[0];
            }
        }
        return -1;
    }
};