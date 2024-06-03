
/*
思路
substring + 找个数 -> prefix + map
odd/even -> bitmap -> using int value with bit operations to represent
map的key是奇偶性表示数，value是此奇偶性下之前已出现的substring的个数

every time we move to the next position:
result += count[bitmask]：如果在第 i 个字符之前，整个前缀的位掩码和我们当前的位掩码相同（即 bitmask），这意味着从 i+1 到 j 的子字符串也是“wonderful”的。因为两者的奇偶性相同，所以它们之间的字符出现次数的差异肯定是偶数次，保证了子字符串的奇偶性结构没有被破坏。
if there exists an position i, such that the substring from 0 -> i contains the same odd/even number of characters as the substring from 0 -> j, then the substring from i+1 -> j must be wonderful. There is a total of count[bitmask] such positions.

对每一个字符反转奇偶性
result += count[toggled_bitmask]：如果 count[toggled_bitmask] 中存在记录，意味着之前有一个前缀，其位掩码与当前位掩码只有一个字符的奇偶性不同。换句话说，这意味着我们可以找到一个前缀，使得从该前缀结束到当前位置的子字符串中，只有一个字符出现了奇数次，而其他字符都是偶数次，这样的子字符串也是“wonderful”的。
we flip each character once, if there exists an position i, such that the substring from 0->i contains only 1 character which its parity not the same as the substring from 0->j, then it means the substrnig from i+1 -> j contains only 1 character which the number is odd, it is also a wonderful substring

a = b^(1<<idx)，反转第idx位的0/1
*/


class Solution {
public:
    long long wonderfulSubstrings(string word) {
        std::unordered_map<int, int> count_map = {{0, 1}}; // 初始化为0，1，key是奇偶性代表数，value是个数
        int mask = 0;
        long long res = 0;
        for (auto& c: word) {
            mask ^= (1<<(c-'a'));
            if (count_map.count(mask)) {
                res += count_map[mask];
            }
            // flip each character
            for (int i = 0; i < 10; i++) {
                int cur_mask = mask ^ (1 << i);
                if (count_map.count(cur_mask)) {
                    res += count_map[cur_mask];
                }
            }
            count_map[mask]++; // the number of substring that equals to current parity + 1
        }
        return res;

    }
};