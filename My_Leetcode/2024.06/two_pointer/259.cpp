// 和之前做的三角形那题一样
// 先sort
// 固定第三个值，双指针找另外两个
// O(n^2)

#include <vector>

using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right = 0;
        int result = 0;

        for (int i = 0; i < (int)nums.size()-2; i++) {   //这里要转成int类型，因为nums.size()是size_t, size_t类型不能表示负数，成了一个INT_MAX
            // std::cout << "loop" << std::endl;
            // a+b 类型双指针，双指针从两侧往中间移动，类似三角形那题
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                if (nums[left] + nums[right] < target - nums[i]) {
                    result += (right-left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
}