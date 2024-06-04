/*
prefix_sum is the current sum % p
remove 掉的subarray之和对p的余数与 total_sum % p 相同
remove 掉的subarray (i+1, j) 之和对p的余数 = (0~j)余数 - (0~i)余数 + p if needed
*/

# include <vector>
# include <unordered_map>

using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int min_size = INT_MAX;
        unordered_map<int, int> presum_map;
        int pre_sum = 0;
        // presum_map[0] = -1;
        int target_remainder;
        long long sum = 0;
        for (auto& num: nums) {
            sum += (long long)num;
        }
        target_remainder = sum % p;
        // std::cout << "target_remainder: " << target_remainder << std::endl;
        if (target_remainder == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            pre_sum = (pre_sum + nums[i]) % p;
            // std::cout << "pre_sum: " << pre_sum << std::endl;
            if (pre_sum < target_remainder) {
                if (presum_map.count(pre_sum + p - target_remainder)) {
                    min_size = min(min_size, i - presum_map[pre_sum + p - target_remainder]);
                    
                }
            } else if (pre_sum == target_remainder && presum_map.count(pre_sum)) {   // 这个地方应该有更好的处理方法，在这个地方卡了很久
                    min_size = min(min_size, presum_map[pre_sum] + 1);
            } else {
                if (presum_map.count(pre_sum - target_remainder)) {
                    // std::cout << "111" << std::endl;
                    min_size = min(min_size, i - presum_map[pre_sum - target_remainder]);
                }
            }
            presum_map[pre_sum] = i;
        }
        if (min_size == INT_MAX || min_size == nums.size()) {
            return -1;
        }
        return min_size;
    }
};


class Solution2 {
public:
    int minSubarray(vector<int>& nums, int p) {
        int min_size = INT_MAX;
        unordered_map<int, int> presum_map;
        int pre_sum = 0;
        presum_map[0] = -1;  // 还是要初始化，就规避了后面复杂的判断
        int target_remainder;
        long long sum = 0;
        for (auto& num: nums) {
            sum += (long long)num;
        }
        target_remainder = sum % p;
        // std::cout << "target_remainder: " << target_remainder << std::endl;
        if (target_remainder == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            pre_sum = (pre_sum + nums[i]) % p;
            // std::cout << "pre_sum: " << pre_sum << std::endl;
            if (pre_sum < target_remainder) {
                if (presum_map.count(pre_sum + p - target_remainder)) {
                    min_size = min(min_size, i - presum_map[pre_sum + p - target_remainder]);
                    
                }
            } 
            // else if (pre_sum == target_remainder && presum_map.count(pre_sum)) {
            //         min_size = min(min_size, presum_map[pre_sum] + 1);
            // } 
            else {
                if (presum_map.count(pre_sum - target_remainder)) {
                    // std::cout << "111" << std::endl;
                    min_size = min(min_size, i - presum_map[pre_sum - target_remainder]);
                }
            }
            presum_map[pre_sum] = i;
        }
        if (min_size == INT_MAX || min_size == nums.size()) {
            return -1;
        }
        return min_size;
    }
};

