//
// Created by 罗万千 on 2021/3/24.
// Exceed time limit, 超时
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0)
            return 0;

        const int m = 1000000007;
        long long sum;
        long long currentSum = 0;
        long long maxSum = 0;

        for (int i=0; i<k; i++) {
            for (int j=0;j<arr.size();j++) {
                sum = arr[j] + currentSum;
                if (sum >= arr[j])
                    currentSum = sum;
                else
                    currentSum = arr[j];
                if (currentSum > maxSum)
                    maxSum = currentSum;
            }
        }
        return maxSum % m;
    }
};

int main()
{
    vector<int> arr = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
    int k = 100000;
    Solution solu;
    cout << solu.kConcatenationMaxSum(arr, k) << endl;
}

