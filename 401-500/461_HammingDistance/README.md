# LeetCode 461. Hamming Distance

## 题目

两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 `x` 和 `y`，计算并返回它们之间的汉明距离。

示例 1：

```
输入：x = 1, y = 4
输出：2
解释：
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
```

示例 2：

```
输入：x = 3, y = 1
输出：1
```

提示：

* `0 <= x, y <= 2^31 - 1`


## 题解1

代码：[solution1.cpp](solution1.cpp)

思路：首先 `x XOR y` 将两个数字不同位置的二进制1进行合并，然后判断二进制1的个数。判断二进制1的个数，这里用了 `LeetCode 338. Counting Bits` 题解中的`Brian Kernighan`算法

```c++
int count = 0;
while (z > 0) {
    z = z & (z - 1);
    count++;
}
```