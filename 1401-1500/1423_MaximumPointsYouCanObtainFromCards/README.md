# LeetCode 1423. Maximum Points You Can Obtain from Cards

- [LeetCode 1423. Maximum Points You Can Obtain from Cards](#leetcode-1423-maximum-points-you-can-obtain-from-cards)
  - [题目](#题目)
  - [题解1](#题解1)

## 题目

There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer `k`, return the maximum score you can obtain.

Example 1:

```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

Example 2:

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

Example 3:

```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
``` 

Constraints:

* `1 <= cardPoints.length <= 10^5`
* `1 <= cardPoints[i] <= 10^4`
* `1 <= k <= cardPoints.length`

## 题解1

代码：[solution1.cpp](solution1.cpp)

滑动窗口，类似 [LeetCode 643. Maximum Average Subarray I](../601-700/../../601-700/643_MaximumAverageSubarrayI/README.md) 解题。初始窗口为 `[len-k, len-1]`，算该窗口的和，然后向右移动窗口，每移动一次，就算一次窗口和（优化计算方法参考LeetCode 643），移动k次即可