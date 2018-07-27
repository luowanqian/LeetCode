#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        else if (b.empty())
            return a;

        int len_a, len_b;
        int i, j, pos;
        int num_a, num_b, num;
        int carry;
        string *sum;

        len_a = a.size();
        len_b = b.size();
        if (len_a > len_b) {
            sum = &a;
            pos = len_a - 1;
        } else {
            sum = &b;
            pos = len_b - 1;
        }

        i = len_a - 1;
        j = len_b - 1;
        carry = 0;
        while (i>=0 || j>=0) {
            num_a = i >= 0 ? a[i--] - '0' : 0;
            num_b = j >= 0 ? b[j--] - '0' : 0;

            num = num_a + num_b + carry;
            carry = num / 2;
            num = num % 2;
            (*sum)[pos--] = num + '0';
        }
        if (carry == 1)
            (*sum).insert(0, 1, '1');

        return *sum;
    }
};

int main()
{
    string str1 = "1010";
    string str2 = "1011";
    Solution solu;

    cout << solu.addBinary(str1, str2) << endl;

    return 0;
}
