/*
以前竟然没用过multiset
感觉比priority_queue强大的多啊
- 同样是find堆顶，都是O(1)
- set可以在O(logn)找到任意的元素并且erase，pq不行，pq只能pop堆顶，且也是O(logn)
- set可以在O(logn)做insert，pq也是

有什么场景下pq比set更好吗？没想到
*/
#include <queue>
#include <set>

using namespace std;

class MKAverage {
public:
    queue<int> last_m_nums;
    int m, k;
    multiset<int> low, mid, high;
    long long sum = 0; 

    MKAverage(int m, int k): m(m), k(k) {

    }
    
    void addElement(int num) {
        // num must be one of the 3 multisets
        if (high.empty() || num >= *high.begin()) {
            high.insert(num);
        } else if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            mid.insert(num);
            sum += num;
        }
        // push to the queue
        last_m_nums.push(num);
        // need to pop the queue
        if (last_m_nums.size() > m) {
            int pop_num = last_m_nums.front();
            last_m_nums.pop();
            // deal with the pop_num in the multiset and 
            // find the pop_num in low
            if (low.find(pop_num) != low.end()) {
                low.erase(low.find(pop_num));   
            } else if (high.find(pop_num) != high.end()) {
                high.erase(high.find(pop_num));
            } else {
                mid.erase(mid.find(pop_num));
                sum -= pop_num;
            }
        }
        // rebalance multiset
        while (high.size() > k) {
            int v = *high.begin();
            mid.insert(v);
            sum += v;
            high.erase(high.begin());
        }
        while (low.size() > k) {
            int v = *low.rbegin();
            mid.insert(v);
            sum += v;
            low.erase(prev(low.end()));
        }
        while (low.size() < k && mid.size()) {
            int v = *mid.begin();
            mid.erase(mid.begin());
            sum -= v;
            low.insert(v);
        }
        while (high.size() < k && mid.size()) {
            int v = *mid.rbegin();
            mid.erase(prev(mid.end()));
            sum -= v;
            high.insert(v);
        }
    }
    
    int calculateMKAverage() {
        if (last_m_nums.size() < m) {
            return -1;
        }
        return sum/(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */