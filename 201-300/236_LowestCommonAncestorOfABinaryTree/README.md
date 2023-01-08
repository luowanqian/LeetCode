# LeetCode 236. Lowest Common Ancestor of a Binary Tree

- [LeetCode 236. Lowest Common Ancestor of a Binary Tree](#leetcode-236-lowest-common-ancestor-of-a-binary-tree)
  - [题目](#题目)
  - [题解1](#题解1)

## 题目

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

示例1：

![](lc236_assets/lc236_1.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 
```

示例2：

![](lc236_assets/lc236_2.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
```

示例3：

```
输入：root = [1,2], p = 1, q = 2
输出：1
```

提示：

* 树中节点数目在范围 `[2, 10^5]` 内
* `-10^9 <= Node.val <= 10^9`
* 所有 `Node.val` 互不相同
* `p != q`
* `p` 和 `q` 均存在于给定的二叉树中

## 题解1

代码：[solution1.cpp](solution1.cpp)

![](lc236_assets/lc236_1.png)

最近公共祖先LCA有两种情况：

* 节点 node1 是节点 node2 的父节点，此时LCA就是节点 node1，例如 p = 7, q = 5，此时LCA为节点5
* 节点 node1 和节点 node2 分别位于节点 node3 的左右子树中，此时LCA是节点 node3，例如 p = 6, q = 8，此时LCA为节点3

不管是哪种情况，都需要先知道目标节点p和q是否在当前节点的左右子树，因此本题采用 **自底向上** 解体思路

**自底向上** 的递归函数 `bottom_up(root)`

```c++
1. return specific value for null node
2. left_ans = bottom_up(root.left)   // call function recursively for left child
3. right_ans = bottom_up(root.right) // call function recursively for right child
4. return answers  // answer <-- left_ans, right_ans, root.val
```