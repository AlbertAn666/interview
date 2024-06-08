#include <vector>
#include <queue>

using namespace std;

struct Comp {
    bool operator()(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), Comp());
        priority_queue<int, vector<int>, less<int>> pq;
        int total_time = 0;
        int result = 0;
        for (auto& course: courses) {
            int t = course[0];
            int d = course[1];
            if (t + total_time <= d) {
                total_time += t;
                pq.push(t);
                result++;
            } else if (!pq.empty() && pq.top() > t) {  // 一定要判断pq.top() > t，否则不能交换
                int top = pq.top();
                total_time = total_time - top + t;
                // 这种情况下，pop出来最大的那个课，把当前课加进去，其他的课一定能finish，当前课也能finish，并且此时total_time最小
                // 其实是greedy
                pq.pop();
                pq.push(t);
            }
        }
        return result;
    }
};