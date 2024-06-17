/*
从大到小遍历
找到本次跳奇数次和之前调偶数次
和本次跳偶数次和之前跳奇数次的关系
用map，其实就是一个堆，来排序，方便logn时间找到值
*/
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int get_smaller_index(map<int, int>& value_pos, int value) {
        auto it = value_pos.upper_bound(value);
        if (it == value_pos.begin()) {
            return -1;
        }
        --it;
        return it->second;
    }

    int oddEvenJumps(vector<int>& arr) {
        map<int, int> value_pos;
        vector<vector<bool>> dp(arr.size(), vector<bool>(2, false));
        int res = 0;
        // dp[i][0]: from point i, and the next jump is odd jump, we could get to the end
        // dp[i][1]: from point i, and the next jump is even jump, we could get to the end

        // the return should be the number of dp[i][0] = 1
        dp[arr.size()-1][0] = true;
        dp[arr.size()-1][1] = true;

        value_pos[arr[arr.size()-1]] = arr.size()-1;

        for (int i = arr.size()-2; i >= 0; i--) {
            // the smallest bigger/equal value
            // std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
            auto bigger_iter = value_pos.lower_bound(arr[i]);
            if (bigger_iter == value_pos.end()) {
                // std::cout << "dp[" << i << "][0] false" << std::endl;
                dp[i][0] = false;
            } else {
                // std::cout << "dp[" << i << "][0] = " << std::endl;
                // std::cout << "bigger_index: " << bigger_iter->second << std::endl;
                dp[i][0] = dp[bigger_iter->second][1];
            }
            // std::cout << "dp[" << i << "][0]: " << dp[i][0] << std::endl; 
            // the biggest smaller/equal value
            int smaller_index = get_smaller_index(value_pos, arr[i]);
            // std::cout << "smaller_index: " << smaller_index << std::endl;
            if (smaller_index == -1) {
                dp[i][1] = false;
            } else {
                dp[i][1] = dp[smaller_index][0];  // the biggest smaller/equal value
            } 
            // std::cout << "dp[" << i << "][1]: " << dp[i][1] << std::endl; 
            value_pos[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); i++) {
            res += (int)dp[i][0];
        }
        return res;
    }
};