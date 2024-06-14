#include <vector>
#include <unordered_map>
#include <map>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        map<int, vector<int>> points_map; // key is the x axile position
        int min_res = INT_MAX;
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            points_map[x].push_back(y);
        } 
        unordered_map<int, int> hash_store;
        for (auto& iter: points_map) {
            int x = iter.first;
            auto& y_positions = iter.second;
            sort(y_positions.begin(), y_positions.end());
            for (int i = 0; i < y_positions.size()-1; i++) {
                for (int j = i+1; j < y_positions.size(); j++) {
                    int y1 = y_positions[i];
                    int y2 = y_positions[j];
                    int hash_key = 40000 * y1 + y2; // 排序之后用一个hash_key来唯一记录一对y1/y2是关键
                    if (hash_store.find(hash_key) != hash_store.end()) {
                        int area = (y2-y1) * (x - hash_store[hash_key]);
                        min_res = min(min_res, area);
                    }
                    hash_store[hash_key] = x;
                }
            }
        }
        return min_res == INT_MAX ? 0 : min_res;
    }
};