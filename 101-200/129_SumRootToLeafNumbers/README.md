# LeetCode 129. Sum Root to Leaf Numbers

- [LeetCode 129. Sum Root to Leaf Numbers](#leetcode-129-sum-root-to-leaf-numbers)
  - [题目](#题目)
  - [题解1](#题解1)


## 题目

给你一个二叉树的根节点 `root` ，树中每个节点都存放有一个 `0` 到 `9` 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 `1 -> 2 -> 3` 表示数字 `123` 。

计算从根节点到叶节点生成的 **所有数字之和**。

**叶节点** 是指没有子节点的节点。

示例1：

![](lc129_assets/lc129_1.jpeg)

```
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```

示例2：

![](lc129_assets/lc129_2.jpeg)

```
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
```

提示：

* 树中节点的数目在范围 `[1, 1000]` 内
* `0 <= Node.val <= 9`
* 树的深度不超过 `10`

## 题解1

代码：[solution1.cpp](solution1.cpp)

这道题采用 **自顶而下** 求解思路，因为只有遍历到叶子节点才能知道从根节点到叶子节点所表示的数字

自顶而下递归函数 `top_down(root, params)`：

```c++
1. return specific value for null node
2. update the answer if needed  // answer <-- params
3. left_ans = top_down(root.left, left_params)  // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed  // answer <-- left_ans, right_ans
```

父节点传递给子节点的params是从根节点到该父节点所表示的数字

![](lc129_assets/lc129_2.jpeg)

例如父节点9传递给子节点5的params为 `4*10 + 9 = 49`