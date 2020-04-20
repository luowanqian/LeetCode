#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> num(num1.size()+num2.size()+2, 0);
        string result(num1.size()+num2.size()+2, 0);
        int pos, first_nzero, res;

        for (int i=num1.size()-1; i>=0; i--) {
            for (int j=num2.size()-1; j>=0; j--) {
                pos = (num1.size()-1-i) + (num2.size()-1-j);
                num[pos] += (num1[i] - '0') * (num2[j] - '0');
                while ((res = num[pos] / 10) >= 1) {
                    num[pos] %= 10;
                    num[++pos] += res;
                }
            }
        }
        reverse(num.begin(), num.end());
        first_nzero = -1;
        for (auto i=0; i<num.size(); i++) {
            if (first_nzero == -1 && num[i] > 0)
                first_nzero = i;
            result[i] = num[i] + '0';
        }
        if (first_nzero == -1)
            return result = "0";
        return result.substr(first_nzero);
    }
};

int main()
{
    string num1 = "9";
    string num2 = "9";
    Solution solu;
    cout << solu.multiply(num1, num2) << endl;
    return 0;
}