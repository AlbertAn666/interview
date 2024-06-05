/* 
1 1 1 0 0 0 1 1 1 1 0
[11100] 011110   5
1110[00] 11110   2
1110[001111] 0   6
11100[0111110]   6
*/ 
#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int cur_flipped = 0;
        int max_length = INT_MIN;

        while(right < nums.size()) {
            if (nums[right] == 0) {
                cur_flipped++;
            }
            if (cur_flipped > k) {
                while(left < right && nums[left] == 1) {
                    left++;
                }
                if (nums[left] == 0) {
                    left++;
                    cur_flipped--;
                }

            }

            max_length = max(max_length, right-left+1);
            right++;
        }
        return max_length;
    }
};

