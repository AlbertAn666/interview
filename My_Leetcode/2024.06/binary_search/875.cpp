#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for (auto& pile: piles) {
            right = max(right, pile);
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            long time = getTime(piles, mid);
            // std::cout << "speed: " << mid << " time: " << time << std::endl;
            if (time <= h){
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    long getTime(vector<int>& piles, int speed) {
        int ret = 0;
        for (auto& pile: piles) {
            ret += pile%speed == 0 ? pile/speed : pile/speed+1;
        }
        return ret;
    }
};