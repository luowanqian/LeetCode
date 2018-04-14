#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;

        for (int i=0; i<moves.size(); i++) {
            switch (moves[i]) {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
        }

        return (x == 0 && y == 0);
    }
};

int main()
{
    Solution solu;
    string str1 = "UD";
    cout << str1 << ": " << solu.judgeCircle(str1) << endl;
    string str2 = "LL";
    cout << str2 << ": " << solu.judgeCircle(str2) << endl;

    return 0;
}