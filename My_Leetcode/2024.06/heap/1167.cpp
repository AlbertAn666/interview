#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& stick: sticks) {
            pq.push(stick);
        }
        int result = 0;
        while(pq.size() > 1) {
            int cur_min1 = pq.top();
            pq.pop();
            int cur_min2 = pq.top();
            pq.pop();
            // std::cout << cur_min1 << " " << cur_min2 << std::endl;
            result += cur_min1 + cur_min2;
            pq.push(cur_min1 + cur_min2);
        }
        return result;
    }
};