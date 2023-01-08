# LeetCode 543. Diameter of Binary Tree

- [LeetCode 543. Diameter of Binary Tree](#leetcode-543-diameter-of-binary-tree)
  - [题目](#题目)
  - [题解1](#题解1)

## 题目

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

注意：两结点之间的路径长度是以它们之间边的数目表示

示例1：

![](lc543_assets/lc543_1.jpeg)

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

示例2：

```
Input: root = [1,2]
Output: 1
```

提示：

* The number of nodes in the tree is in the range `[1, 10^4]`.
* `-100 <= Node.val <= 100`

## 题解1

代码：

* [solution1.cpp](solution1.cpp)
* [solution2.cpp](solution2.cpp)

![](lc543_assets/lc543_1.jpeg)

思路：遍历树每个节点，对于节点 node，以该节点 node 为根的树，计算该树直径长度，直径长度等于左子树深度加上右子树深度，即

```
直径长度 = max(left_tree_depth, right_tree_depth)
```

例如节点 2，可知以该节点为根的路径长度为 max(1, 1) = 2，路径为 [4, 2, 5]

由上思路可知该题是 **自底向上** 解题思路，因为需要知道左右子树的深度，才能计算直径长度