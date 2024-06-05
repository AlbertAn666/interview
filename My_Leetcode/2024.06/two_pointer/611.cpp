/* 
a + b > c => sort
O(n^2)
固定一条边的情况下，
    另外两条边双指针移动

所以可以考虑固定最大边，另外双指针从两侧往中间移
*/
#include <vector>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;

        // 固定最大边，最大边从小到大移动
        for (int i = 2; i < nums.size(); i++) {
            // left pointer starts moving from left, right pointer starts moving from right
            int left = 0, right = i - 1;
            while(left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right-left;
                    right--;
                } else {
                    left++;
                }
            } 
        }
        return result;
    }
};