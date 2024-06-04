#include <string>
#include <vector>
#include <queue>


using namespace std;

class Solution_3168 {
public:
    int minimumChairs(string s) {
        int init = 0;
        int min_val = INT_MAX;
        for (auto& c : s) {
            if (c == 'E') {
                init -= 1;
            } else {
                init += 1;
            }
            min_val = min(init, min_val);
        }
        return -min_val;
    }
};

class Solution_3169 {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int result = meetings[0][0]-1;
        priority_queue<int, vector<int>, less<int>> pq;
        pq.push(meetings[0][1]);
        for (int i = 1; i < meetings.size(); i++) {
            auto& meeting = meetings[i];
            int start = meeting[0];
            int end = meeting[1];
            if (!pq.empty() && pq.top() < start) {
                result += start-pq.top() - 1;
                pq = priority_queue<int, vector<int>, less<int>>();
            }
            pq.push(end);
        }
        int final_top = pq.top();
        if (days - final_top > 0) {
            result += days - final_top;
        }
        return result;
    }
};


class Solution_3170 {
public:
    struct Element {
        char character;
        int index;
        
        Element(char c, int i) : character(c), index(i) {}
    };
    
    struct Comp {
        bool operator()(const Element& e1, Element& e2) {
            if (e1.character == e2.character) {
                return e1.index < e2.index;
            } 
            return e1.character > e2.character;
        }
    };
    
    string clearStars(string s) {
        priority_queue<int, vector<int>, greater<int>> removed_index;
        std::string result_string;
        priority_queue<Element, std::vector<Element>, Comp> pq;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push(Element(s[i], i));
            } else {
                removed_index.push(i);
                // std::cout << "push " << i << std::endl;
                Element top_e = pq.top();
                pq.pop();
                removed_index.push(top_e.index);
                // std::cout << "push " << top_e.index << std::endl;
            }
        }
        
        int cur_index = 0;
        // debug_removed_index(removed_index);
        while(!removed_index.empty()) {
            // std::cout << "top index: " << removed_index.top() << "cur_index: " << cur_index << std::endl;
            // std::cout << "substr: " <<  s.substr(cur_index, removed_index.top() - cur_index) << std::endl;
            // if (cur_index == removed_index.top()) {
            //     removed_index.pop()
            // }
            result_string += s.substr(cur_index, removed_index.top() - cur_index);
            // std::cout << "result_string: "<< result_string << std::endl;
            cur_index = removed_index.top() + 1;
            removed_index.pop();
        }
        // std::cout << "result_string: "<< result_string << "cur_index: " << cur_index;
        result_string += s.substr(cur_index, s.size() - cur_index);
        return result_string;
    }
};