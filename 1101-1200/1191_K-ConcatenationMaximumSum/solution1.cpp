//
// Created by 罗万千 on 2021/3/24.
// refer: https://leetcode-cn.com/problems/k-concatenation-maximum-sum/solution/kao-lu-hao-you-ji-chong-qing-kuang-by-docker-2/
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

        int mod = 1000000007;
        int n = arr.size();
        long long currentSum, maxSum;

        currentSum = maxSum = 0;
        for (int i=0; i<n; i++) {
            currentSum += arr[i];
            if (arr[i] > currentSum)
                currentSum = arr[i];
            if (currentSum > maxSum)
                maxSum = currentSum;
        }

        if (k == 1)
            return maxSum % mod;

        long long prefix, suffix;
        long long maxPrefix, maxSuffix;
        long long sumMaxPSfix;

        prefix = maxPrefix = arr[0];
        suffix = maxSuffix = arr[n-1];
        for (int i=1, j=n-2; i<n; i++, j--) {
            prefix += arr[i];
            suffix += arr[j];
            if (prefix > maxPrefix)
                maxPrefix = prefix;
            if (suffix > maxSuffix)
                maxSuffix = suffix;
        }
        sumMaxPSfix = maxSuffix + maxPrefix;

        return max(0ll, max(maxSum, max(sumMaxPSfix, sumMaxPSfix+(k-2)*prefix)) % mod);
    }
};

int main()
{
    vector<int> arr = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
    int k = 100000;
    Solution solu;
    cout << solu.kConcatenationMaxSum(arr, k) << endl;
}

