/*
 * My Solution
 * 2020-08-11
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <iostream>
#include <vector>
#include "nested_list.h"
using namespace std;

class NestedIterator {
private:
    vector<int> nums;
    int pos;
public:
    void dfs(const vector<NestedInteger> &nestedList) {
        for (int i=0; i<nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                nums.push_back(nestedList[i].getInteger());
            } else {
                dfs(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        pos = 0;
    }

    int next() {
        return nums[pos++];
    }

    bool hasNext() {
        return pos < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    return 0;
}