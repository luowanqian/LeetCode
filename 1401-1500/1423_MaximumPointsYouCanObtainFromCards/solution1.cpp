/*
 * LeetCode 1423. Maximum Points You Can Obtain from Cards
 * History:
 *  2023.1.12 : first version
 */

#include "Print.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max = 0;
        int total = 0;
        int len = cardPoints.size();

        // calculate last k card points
        for (int i = len-k; i < len; i++) {
            total += cardPoints[i];
        }
        max = total;

        // take all cards
        if (k == len) {
            return max;
        }

        // try k times
        int low = len - k;
        int high = len - 1;
        for (int i = 0; i < k; i++) {
            high++;
            high = high % len;
            total += cardPoints[high];

            total -= cardPoints[low];
            low++;
            low = low % len;

            if (total > max) {
                max = total;
            }
        }

        return max;
    }
};

int main()
{
    Solution sol;
    int k;

    k = 2;
    vector<int> nums1 {2,2,2};
    printVector(nums1);
    cout << "Take " << k << ": " << sol.maxScore(nums1, k) << endl;

    k = 7;
    vector<int> nums2 {9,7,7,9,7,7,9};
    printVector(nums2);
    cout << "Take " << k << ": " << sol.maxScore(nums2, k) << endl;

    k = 1;
    vector<int> nums3 {1, 1000, 1};
    printVector(nums3);
    cout << "Take " << k << ": " << sol.maxScore(nums3, k) << endl;

    k = 3;
    vector<int> nums4 {1,79,80,1,1,1,200,1};
    printVector(nums4);
    cout << "Take " << k << ": " << sol.maxScore(nums4, k) << endl;

    return 0;
}