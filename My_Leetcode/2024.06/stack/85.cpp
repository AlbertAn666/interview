#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> new_matrix(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_area = 0;
        // 首先处理一边行 O(mn)
        for (int i = 0; i < matrix.size(); i++) {
            auto& row = matrix[i];
            int num = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {                 
                    new_matrix[i][j] = ++num;
                } else {
                    num = 0;
                }
            }
        }
        // for (int i = 0; i < new_matrix.size(); i++) {
        //     for (int j = 0; j < new_matrix[0].size(); j++) {
        //         std::cout << " " << new_matrix[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // 在用84题的方法处理每一列
        for (int j = 0; j < new_matrix[0].size(); j++) {
            std::vector<int> column;
            for (int i = 0; i < new_matrix.size(); i++) {
                column.push_back(new_matrix[i][j]);
            }
            
            max_area = max(max_area, largestRectangleArea(column));
        }
        return max_area;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> new_heights(heights.size()+2, 0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            new_heights[i+1] = heights[i];
        }

        stack<int> st; // 存储下标
        st.push(0);
        for (int i = 1; i < new_heights.size(); i++) {
            // std::cout << "new_heights: " << new_heights[i] << std::endl;
            while (new_heights[i] < new_heights[st.top()]) {
                int height = new_heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                // std::cout << "height: " << height << " width: " << width << std::endl;
                max_area = max(max_area, height * width);

            }
            
            st.push(i);
        }
        return max_area;
    }
};
