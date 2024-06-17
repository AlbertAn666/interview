#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> height_st;
        height_st.push(0);
        int ans = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!height_st.empty() && height[i] >= height[height_st.top()]) {
                int cur_top = height_st.top();
                height_st.pop();
                if (height_st.empty()) {
                    break;
                }
                int cur_width = i - height_st.top() - 1;
                int cur_height = min(height[i], height[height_st.top()]) - height[cur_top];
                ans += cur_width * cur_height;
            }
            height_st.push(i);
        }
        return ans;
    }
};

