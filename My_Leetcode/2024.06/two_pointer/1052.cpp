#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int nums_not_grumpy = 0;
        int max_not_grumpy_in_grumpy = 0;
        int cur_not_grumpy_in_grumpy = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                nums_not_grumpy += customers[i];
            }
            if (i < minutes && grumpy[i] == 1) {
                cur_not_grumpy_in_grumpy += customers[i];
            }
        }
        // std::cout << nums_not_grumpy << " " << cur_not_grumpy_in_grumpy << std::endl;
        max_not_grumpy_in_grumpy = cur_not_grumpy_in_grumpy;
        if (customers.size() <= 1) {
            return nums_not_grumpy + max_not_grumpy_in_grumpy;
        }
        for (int i = 1; i < customers.size() - minutes + 1; i++) {
            if (grumpy[i-1] == 1) {
                cur_not_grumpy_in_grumpy -= customers[i-1];
            }
            if (grumpy[i+minutes-1] == 1) {
                cur_not_grumpy_in_grumpy += customers[i+minutes-1];
            }
            // std::cout << "cur_not_grumpy_in_grumpy " << cur_not_grumpy_in_grumpy << std::endl;
            if (cur_not_grumpy_in_grumpy > max_not_grumpy_in_grumpy) {
                max_not_grumpy_in_grumpy = cur_not_grumpy_in_grumpy;
            }
        }

        return nums_not_grumpy + max_not_grumpy_in_grumpy;
    }
};