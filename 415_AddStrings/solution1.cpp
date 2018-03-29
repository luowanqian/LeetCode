#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.size() == 0)
            return num2;
        else if (num2.size() == 0)
            return num1;

        string num;
        bool flag = false;
        int i = num1.size() - 1, j = num2.size() - 1;
        int sum = 0;
        while (i >= 0 || j >= 0) {
            if (i < 0)
                sum = num2[j] - '0';
            else if (j < 0)
                sum = num1[i] - '0';
            else
                sum = (num1[i] - '0') + (num2[j] - '0');

            if (flag) {
                sum += 1;
                flag = false;
            }
            if (sum >= 10)
                flag = true;

            sum = sum % 10;
            num.push_back(sum + '0');

            i--;
            j--;
        }
        if (flag)
            num.push_back('1');

        return string(num.rbegin(), num.rend());
    }
};

int main()
{
    Solution solu;
    string num1, num2;

    num1 = "123";
    num2 = "87";

    cout << num1 << " + " << num2 << " = "
         << solu.addStrings(num1, num2) << endl;
    return 0;
}