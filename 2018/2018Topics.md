# 2018

共八道程序设计题，3 个小时，共 150 分。

### 1. 循环数组
（思路 5 points, C/C++ 代码 10 points）

数组 R 存放了 100 个整数，设计一个算法，时间复杂度不超过 O(n) 空间复杂度不超过 O(1)，实现将 R 中所有整数左移 25 个位置。

如：
[0,1,2,3,4,……,98,99] --> [25,26,27,……,99,0,1,……,24]

### 2. 奇偶车厢排序
（5+10 points）

一趟列车车厢顺序正常 [1,2,3,4……]，现要求奇数车厢在前，偶数车厢在后，设计算法并使用程序实现。

### 3. 二叉树最大宽度
（5+10 points）

求一颗二叉树最大宽度。

### 4. 城墙问题
（5+10 points）

+--------------+    +--------------+
| +----------+ |    | +----------+ |
| | +--+ +-+ | |    | | +------+ | |
| | | A| | | | |    | | |  B   | | |
| | +--+ +-+ | |    | | +------+ | |
| +----------+ |    | +----------+ |
+--------------+    +--------------+

一个人一次只能翻越一道围墙，翻越一道围墙计数为 1，如图所示，从 A 到 B 一共翻越了 6 道围墙，设计一个算法，记录一个人翻越的围墙数，即从 A 到 B 的情况。并用程序实现。

### 5. 数字中有多少“1”
（10+10 points）

一个整数，长度为 len。

比如 12 长度为 1，那么写下 1,2,3,4,5,6,7,8,9,10,11,12。
比如 5 长度为 1，那么写下 1,2,3,4,5。

要求写出函数 f(n)，统计出现的 1 的个数，比如 f(12) = 5, f(5) = 1，要求时间复杂度不大于 O(len)


### 6. 邮票问题 
（10+10 points）

 市面上发行 N 种面值的邮票，一个信封上最多能够贴 M 张邮票。计算从 1 开始，最大连续可贴出的邮资。 

 当 N = 5, M = 4，面值为 1,3,11,15,32 的五种面值邮票可以贴出最大连续邮资区间是 1 到 70。

### 7.  
（10+15 points）


### 8. 分治法数列最值
1. 设计一个简单的算法求数组最大最小值。
2. 设计一个分治算法，将数组分为两半，求数组最大最小值，并给出分治算法时间复杂度。
3. 写出上述两种算法在数组有 5 个元素时的比较次数，比较两种算法。
