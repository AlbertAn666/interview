#include <unordered_map>
#include <vector>

using namespace std;

class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> points_stores;
    // unordered_map<int, vector<int>> y_xs;
    unordered_map<int, vector<int>> x_ys;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        points_stores[y][x]++;
        // y_xs[y].push_back(x);
        x_ys[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        auto& ys = x_ys[x];

        for (int v_y: ys) {
            // std::cout << "v_y: " << v_y << std::endl;
            int length = v_y - y;
            // length = 0 要跳过，否则多算
            if (length == 0) {
                continue;
            }
            int v_x1 = x + length;
            int v_x2 = x - length;
            if (points_stores[v_y].count(v_x1) && points_stores[y].count(v_x1))  {
                ans += points_stores[v_y][v_x1] * points_stores[y][v_x1];
            }
            if (points_stores[v_y].count(v_x2) && points_stores[y].count(v_x2))  {
                ans += points_stores[v_y][v_x2] * points_stores[y][v_x2];
            }
            // std::cout << "ans: " << ans << std::endl;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */