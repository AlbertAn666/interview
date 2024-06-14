#include <string>

using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        string result = "";
        while(p1 < word1.size() && p2 < word2.size()) {
            if (p1 <= p2) {
                result += word1[p1];
                p1 ++;
            } else {
                result += word2[p2];
                p2 ++;
            }
        }
        while (p1 < word1.size()) {
            result += word1[p1];
            p1++;
        }
        while (p2 < word2.size()) {
            result += word2[p2];
            p2++;
        }
        return result;
    }
};