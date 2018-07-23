#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return vector<int>();

        bool flag;
        int num;

        flag = false;
        digits[digits.size()-1] += 1;
        for (int i=digits.size()-1; i>=0; i--) {
            num = digits[i];
            if (flag)
                num++;

            if (num >= 10) {
                flag = true;
                num = num % 10;
            } else {
                flag = false;
            }

            digits[i] = num;
        }
        if (flag)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};


int main()
{
    Solution solu;
    vector<int> digits = {9, 9, 9};
    vector<int> result = solu.plusOne(digits);

    for (auto it=result.begin(); it!=result.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
