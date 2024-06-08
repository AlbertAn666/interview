// do not fuel gas immediately, when we find the gas is < 0, add the gas before using a priority queue
// 其实是一种贪心法，知道到下一个第一个不能到达的站点，再考虑在前面的加油站加油，从最多的开始加，还不能达到，继续加，直到所有都加了也不能到达，则return false
// 如果找到了一个能加的地方，加上之后到了这个站点，那么pre就是现在的位置，我们再去考虑从当前站点往后遍历

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int pre = 0, fuel = startFuel, result = 0;
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < stations.size(); i++) {
            auto& station = stations[i];
            fuel -= station[0] - pre;
            while (fuel < 0 && !pq.empty()) {
                fuel += pq.top();
                // std::cout << "add fuel : " << pq.top() << "cur fuel: " << fuel;
                pq.pop();
                result++;
            }
            if (fuel < 0 && pq.empty()) {
                return -1;
            }
            pq.push(station[1]);
            pre = station[0];
        }
        fuel -= target-pre;
        while (fuel < 0 && !pq.empty()) {
            fuel += pq.top();
            pq.pop();
            result++;
        }
        if (fuel < 0 && pq.empty()) {
            return -1;
        }
        return result;
    }
};