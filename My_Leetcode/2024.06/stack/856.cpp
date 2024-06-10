#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto& c: s) {
            if (c == '(') {
                st.push(0);
            } else {
                int top_value = st.top();
                st.pop();
    
                if (top_value == 0) {
                    // 匹配括号间没有其他括号
                    st.top() += 1;
                } else {
                    // 匹配括号间有其他括号，需要*2
                    st.top() += top_value * 2;
                }
            }
        }
        return st.top();
    }
};
