#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;

        int max_area, area;
        int left, right;
        int min_height;

        left = 0;
        right = height.size() - 1;
        area = 0;
        max_area = 0;
        while (left < right) {
            min_height = min(height[left], height[right]);
            area = min_height * (right - left);
            if (area > max_area)
                max_area = area;

            if (height[left] < height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }

        return max_area;
    }
};

int main()
{
    vector<int> height = {1, 3, 2, 5, 25, 24, 5};
    Solution solu;
    cout << solu.maxArea(height) << endl;

    return 0;
}
