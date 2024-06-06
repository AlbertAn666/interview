#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int p1 = 0, p2 = 0;
        vector<vector<int>> result;
        while(p1 < firstList.size() && p2 < secondList.size()) {
            auto& list1 = firstList[p1];
            auto& list2 = secondList[p2];
            int left_bound = max(list1[0], list2[0]);
            int right_bound = min(list1[1], list2[1]);
            if (left_bound <= right_bound) {
                result.push_back({left_bound, right_bound});
            }
            if (list1[1] > list2[1]) {
                p2++;
            } else {
                p1++;
            }
        }
        return result;
    }
};

/* follow up: how to find the union set？*/
class Solution2 {
public:
    vector<vector<int>> intervalUnionSet(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       int p1 = 0, p2 = 0;
        vector<vector<int>> result;
        while(p1 < firstList.size() && p2 < secondList.size()) {
            auto& list1 = firstList[p1];
            auto& list2 = secondList[p2];
            if (list1[0] < list2[0]) {
                if (result.empty() || list1[0] > result.back()[1]) {
                    result.push_back(list1);
                } else {
                    auto& back_list = result.back();
                    back_list[1] = list1[1];
                }
                p1++;
            } else {
                if (result.empty() || list2[0] > result.back()[1]) {
                    result.push_back(list2);
                } else {
                    auto& back_list = result.back();
                    back_list[1] = list2[1];
                }
                p2++;
            }
        }
        while (p1 < firstList.size()) {
            auto& list1 = firstList[p1];
            if (result.empty() || list1[0] > result.back()[1]) {
                result.push_back(list1);
            } else {
                auto& back_list = result.back();
                back_list[1] = list1[1];
            }
            p1++;
        }
         while (p2 < secondList.size()) {
            auto& list2 = secondList[p2];
            if (result.empty() || list2[0] > result.back()[1]) {
                result.push_back(list2);
            } else {
                auto& back_list = result.back();
                back_list[1] = list2[1];
            }
            p2++;
        }
        return result;
    }
};

/* follow up: how to find intersactions among multiple list？ */
// 应该要用上heap，明天再想吧
// 明天主题：堆