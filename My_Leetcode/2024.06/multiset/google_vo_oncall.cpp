#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct TimeSlot {
    int start;
    int end;
    string name;

    TimeSlot(int s, int e, string n) : start(s), end(e), name(n) {}
};

vector<string> mergeIntervals(vector<TimeSlot>& intervals) {
    map<int, set<string>> timePoints;

    // 拆分时间段并记录每个时间点的人员信息
    for (const auto& interval : intervals) {
        timePoints[interval.start].insert(interval.name);
        timePoints[interval.end].insert(interval.name);
    }

    // 创建一个映射来记录每个时间点的人员集合
    map<int, set<string>> activeIntervals;
    for (const auto& interval : intervals) {
        for (int t = interval.start; t < interval.end; ++t) {
            activeIntervals[t].insert(interval.name);
        }
    }

    // 生成输出结果
    vector<string> result;
    auto it = activeIntervals.begin();
    while (it != activeIntervals.end()) {
        int start = it->first;
        auto currentSet = it->second;
        int end = start;
        while (it != activeIntervals.end() && it->second == currentSet) {
            end = it->first + 1;
            ++it;
        }
        string intervalStr = "[" + to_string(start) + ", " + to_string(end) + "] ";
        string names;
        for (const auto& name : currentSet) {
            if (!names.empty()) names += ", ";
            names += name;
        }
        result.push_back(intervalStr + names);
    }

    return result;
}

int main() {
    vector<TimeSlot> intervals = {
        {10, 20, "Sarah"},
        {0, 5, "Lisa"},
        {1, 13, "Jack"}
    };

    vector<string> result = mergeIntervals(intervals);
    for (const auto& res : result) {
        cout << res << endl;
    }

    return 0;
}