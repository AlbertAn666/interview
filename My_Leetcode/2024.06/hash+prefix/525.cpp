/*
0 -> + (-1)
1 -> + 1
unordered_map<int, first_pos> to track prefix sum
if 0 ~ i prefix sum equals to 0 ~ j prefix sum, then i+1 ~ j is a satified array, with length j - (i+1) + 1 = j-i
*/

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> presum_pos;
        int max_length = INT_MIN;
        int pre_sum = 0;
        presum_pos[0] = -1; // initialization：ex [0,1], the output should be 2
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == 0) {
                pre_sum += -1;
            } else {
                pre_sum += 1;
            }
            if (!presum_pos.count(pre_sum)) {
                presum_pos[pre_sum] = i;
            } else {
                max_length = max(max_length, i - presum_pos[pre_sum]);
            }
        }
        return max_length == INT_MIN ? 0 : max_length;  // 这里记得判断
    }
};