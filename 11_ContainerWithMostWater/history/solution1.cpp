/*
 * My Solution
 * 2020-08-09
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area, area;
        int left, right;
        int min_height;

        left = 0;
        right = height.size() - 1;
        max_area = (right - left) * min(height[left], height[right]);
        while (left < right) {
            min_height = min(height[left], height[right]);
            area = (right - left) * min_height;
            if (area > max_area)
                max_area = area;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_area;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solu;
    int max_area = solu.maxArea(height);
    cout << "Max area: " << max_area << endl;

    return 0;
}