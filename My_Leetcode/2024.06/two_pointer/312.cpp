// two pointer + dp
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = 2; i <= n+1; i++) {   // i从左到右
            for (int j = i - 2; j >= 0; j--) {  // j必须从i到左，因为要先从小区间往大区间走
                for (int k = j+1; k <= i-1; k++) {  // k从j+1到i-1, 在开区间i,j之间
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[j][k] + rec[k][i];
                    rec[j][i] = max(rec[j][i], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};