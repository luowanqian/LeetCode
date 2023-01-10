# LeetCode 674. Longest Continuous Increasing Subsequence

- [LeetCode 674. Longest Continuous Increasing Subsequence](#leetcode-674-longest-continuous-increasing-subsequence)
  - [题目](#题目)
  - [题解1](#题解1)

## 题目

Given an unsorted array of integers nums, return the length of the longest **continuous increasing subsequence** (i.e. subarray). The subsequence must be **strictly** increasing.

A **continuous increasing subsequence** is defined by two indices `l` and `r` (`l < r`) such that it is `[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]` and for each `l <= i < r`, `nums[i] < nums[i + 1]`.

Example 1:

```
Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.
```

Example 2:

```
Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.
```

Constraints:

* `1 <= nums.length <= 10^4`
* `-10^9 <= nums[i] <= 10^9`

## 题解1

代码：[solution1.cpp](solution1.cpp)

本题采用双指针解题，定义两个指针low和high，划定递增区间，在区间`[low, high)`内的元素均是严格递增的，区间大小为 `high - low`。遍历数组，指针`high`不断移动，如果遍历数组时发现元素递减，则计算当前区间的大小，并更新`low`指针为`high`

遍历完数组后，最后再计算一次区间大小，因为可能出现整个数组都是递增的