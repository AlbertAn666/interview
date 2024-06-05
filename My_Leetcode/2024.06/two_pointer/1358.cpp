#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
        int num = 0;
        vector<int> occurences(3, 0);
        occurences[s[right] - 'a']++;
        while(right < s.size()) {
            if (!check_all_occurence(occurences)) {
                right++;
                if (right >= s.size()) {
                    break;
                }
                occurences[s[right] - 'a']++;
            } else {
                while(left < right && check_all_occurence(occurences)) {
                    num += s.size() - right;   // 求个数，这里要这样算
                    occurences[s[left] - 'a']--;
                    left++;
                }
            }
        }
        return num;
    }

    bool check_all_occurence(const vector<int>& occurences) {
        // for (auto& item: occurences) {
        //     std::cout << item << " ";
        // }
        // std::cout << std::endl;
        for (auto& item: occurences) {
            if (item == 0) {
                return false;
            }
        }
        return true;
    }
};