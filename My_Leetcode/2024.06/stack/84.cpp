#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> new_heights(heights.size()+2, 0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            new_heights[i+1] = heights[i];
        }

        stack<int> st; // 存储下标，因为
        st.push(0);
        for (int i = 1; i < new_heights.size(); i++) {
            // std::cout << "new_heights: " << new_heights[i] << std::endl;
            while (new_heights[i] < new_heights[st.top()]) {
                int height = new_heights[st.top()];
                st.pop();
                int width = i - st.top() - 1; // 因为相当于找当前top的height下，左右可以到的值，计算左侧需要先pop再去top，右侧就是i
                // std::cout << "height: " << height << " width: " << width << std::endl;
                max_area = max(max_area, height * width);

            }
            
            st.push(i);
        }
        return max_area;
    }
};