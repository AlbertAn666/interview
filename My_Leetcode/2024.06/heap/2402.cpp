#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        priority_queue<int, vector<int>, greater<int>> idle;  // 这里要用一个pq记录所有available rooms，
        vector<int> meeting_rooms_use_times(n, 0);
        int max_time = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            idle.push(i);
        }
        for (const auto& meeting: meetings) {
            int meeting_start_time = meeting[0];
            int meeting_duration = meeting[1] - meeting[0];

            // 取出的时候不能只取栈的第一个做比较，因为在meeting开始的时候有多个available rooms，取出第一个不满足Each meeting will take place in the unused room with the lowest number条件
            while (!pq.empty() && pq.top().first <= meeting_start_time) {   
                idle.push(pq.top().second);
                pq.pop();
            }
            if (idle.empty()) {
                auto top_meeting_room = pq.top();
                pq.pop();
                // std::cout << "push1: " << top_meeting_room.first + meeting_duration << " " << top_meeting_room.second << std::endl;
                pq.push({(long long)top_meeting_room.first + (long long)meeting_duration, top_meeting_room.second});
                meeting_rooms_use_times[top_meeting_room.second]++;
            } else {
                auto room = idle.top();
                idle.pop();
                // std::cout << "push2: " << meeting[1] << " " << room << std::endl;
                pq.push({(long long)meeting[1], room});
                meeting_rooms_use_times[room]++;
            }

        }

        for (int i = 0; i < meeting_rooms_use_times.size(); i++) {
            if (meeting_rooms_use_times[ans] < meeting_rooms_use_times[i]) {
                ans = i;
            }
        }
        return ans;
    }
};