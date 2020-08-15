/*
 * 2020-08-13
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size());
        stack<int> st;
        for (int i=T.size()-1; i>=0; i--) {
            while (!st.empty() && T[i] >= T[st.top()]) {
                st.pop();
            }
            result[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return result;
    }
};

int main()
{
    vector<int> T = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    Solution solu;
    vector<int> result = solu.dailyTemperatures(T);
    // expect [8,1,5,4,3,2,1,1,0,0]
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}