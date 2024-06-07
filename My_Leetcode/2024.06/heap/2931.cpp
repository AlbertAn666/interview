#include <vector>
#include <queue>

using namespace std;

struct Comp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long result = 0;
        vector<int> pointers(values.size(), values[0].size()-1);  // 这个是没必要的，直接对vector可以用back()和pop_back()来优化
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;  // first store price, second store store index
        for (int i = 0; i < values.size(); i++) {
            pq.push({values[i][pointers[i]], i});
        }

        int day = 1;
        while(!pq.empty()) {
            pair current_pick = pq.top();
            pq.pop();
            int price = current_pick.first;
            int shop_index = current_pick.second;
            // std::cout << "price shop_index: " << price << " " << shop_index << std::endl; 
            pointers[shop_index]--;
            if (pointers[shop_index] >= 0) {
                pq.push({values[shop_index][pointers[shop_index]], shop_index});
            }
            result += (long long)day * (long long)price;
            day++;
        }
        return result;
    }
};