#include <vector>
#include <stdio.h>

using namespace std;

int maximumCustomer(int initial, vector<int>& transactions);

int main() {
    std::vector<int> transactions = {1, -3, 5, -2, 1, 2, 3, -10, 1, 2, 3, -2, -1, 3, 4, 5, -1, 2, 3};
    std::cout << maximumCustomer(1, transactions) << std::endl;
}

// move the right pointer
// -> check the current money,  the current money is smaller than 0 stop move, calculate number of customers
//    -> move the left pointer (till the sum of the money in the moved positions is smaller than 0 || left = right) stop move


int maximumCustomer(int initial, vector<int>& transactions) {
    int left = 0, right = 0;
    int cur = initial;
    int moved_left_sum = 0;
    int ans = 0;
    while (left <= right && right < transactions.size()) {
        std::cout << "left, right: " << left << " " << right << std::endl;
        cur += transactions[right];
        if (cur < 0) {
            ans = max(ans, right - left);
            while (left <= right && moved_left_sum >= 0) {
                std::cout << "left1, right1: " << left << " " << right << std::endl;
                moved_left_sum += transactions[left];
                cur -= transactions[left];
                left++;
            }
        }
         right++;
    }

    return max(ans, right-left);
}