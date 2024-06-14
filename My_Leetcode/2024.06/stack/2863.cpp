#include <stack>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        stack<int> st; // 存index
        int max_len = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                max_len = max(max_len, st.top()-i + 1);
                st.pop();
            }
        }
        return max_len;
    }
};