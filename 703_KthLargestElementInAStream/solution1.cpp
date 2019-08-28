#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 * Assume nums length >= k-1 and k >= 1
 */
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto it=nums.begin(); it!=nums.end(); it++) {
            if (m_heap.size() < k) {
                m_heap.push(*it);
            } else {
                if (m_heap.top() < *it) {
                    m_heap.pop();
                    m_heap.push(*it);
                }
            }
        }

        m_k = k;
    }

    int add(int val) {
        if (m_heap.size() < m_k) {
            m_heap.push(val);
        } else if (m_heap.top() < val) {
            m_heap.pop();
            m_heap.push(val);
        }

        return m_heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> m_heap;
    int m_k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl;    // return 4
    cout << obj->add(5) << endl;    // return 5
    cout << obj->add(10) << endl;   // return 5
    cout << obj->add(9) << endl;    // return 8
    cout << obj->add(4) << endl;    // return 8

    return 0;
}

