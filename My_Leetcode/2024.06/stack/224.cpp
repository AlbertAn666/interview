#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    long getNumber(string s, int& index) {
        std::string num_str = "";
        while (index < s.size() && isdigit(s[index])) {
            num_str += s[index];
            index++;
        }
        return stol(num_str);
    }

    int calculate(string s) {
        string new_str = "";
        for (int i = 0; i < s.size(); i++) {
            if (new_str == "" && (s[i] == '+' || s[i] == '-')) {  // 对于第一个符号就是+/-的情况
                new_str += '0';
            }
            if (s[i] != ' ') {
                new_str += s[i];
            }
        }
        return calculate1(new_str);
    }

    int calculate1(string s) {
        stack<long> nums;
        stack<char> ops;

        // 数字越大，优先级越大
        unordered_map<char, int> priority = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

        int index = 0;
        while(index < s.size()) {
            if (s[index] == ' ') {
                index++;
                continue;
            }
            // 数字: 入数字栈
            if (isdigit(s[index])) {
                long num = getNumber(s, index);
                nums.push(num);
                continue;
            }
            // (: 直接入栈
            if (s[index] == '(') {
                ops.push(s[index]);
                // 对应括号之后立马是+/-的情况
                if (s[index+1] == '+' || s[index+1] == '-') {
                    nums.push(0);
                }
                index++;
                continue;
            }
            // ): 直到找到前一个(
            if (s[index] == ')') {
                char cur_op = ops.top();
                ops.pop();
                while(cur_op != '(') {
                    // 这个时候每一个cur_op一定是同一个优先级的
                    long num1 = nums.top();
                    nums.pop();
                    long num2 = nums.top();
                    nums.pop();
                    if (cur_op == '+') {
                        nums.push(num1+num2);
                    } else if (cur_op == '-') {
                        nums.push(num2-num1);
                    } else if (cur_op == '*') {
                        nums.push(num2*num1);
                    } else if (cur_op == '/') {
                        nums.push(num2/num1);
                    } else if (cur_op == '^') {
                        nums.push(pow(num2, num1));
                    }
                    cur_op = ops.top();
                    ops.pop();
                }
                index++;
            } else {
                // 其他类型运算符，比较栈顶运算符优先级，栈顶高，先算，否则入栈
                char cur_op = s[index];
                while(!ops.empty() && priority[ops.top()] >= priority[cur_op]) {
                    long num1 = nums.top();
                    nums.pop();
                    long num2 = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    if (op == '+') {
                        nums.push(num1+num2);
                    } else if (op == '-') {
                        nums.push(num2-num1);
                    } else if (op == '*') {
                        nums.push(num2*num1);
                    } else if (op == '/') {
                        nums.push(num2/num1);
                    } else if (op == '^') {
                        nums.push(pow(num2, num1));
                    }
                }
                if (ops.empty() || priority[ops.top()] < priority[cur_op]) {
                    ops.push(cur_op);
                    index++;
                }
            }
        }

        while(!ops.empty()) {
            long num1 = nums.top();
            nums.pop();
            long num2 = nums.top();
            nums.pop();
            char op = ops.top();
            ops.pop();
            if (op == '+') {
                nums.push(num1+num2);
            } else if (op == '-') {
                nums.push(num2-num1);
            } else if (op == '*') {
                nums.push(num2*num1);
            } else if (op == '/') {
                nums.push(num2/num1);
            } else if (op == '^') {
                nums.push(pow(num2, num1));
            }
        }
        return nums.top();
    }
};