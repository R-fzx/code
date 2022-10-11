比较亲民的二分+容斥。

二分答案一下 $mid$，求出 $[1, mid]$ 这个区间内幸运数的个数， 则总个数为 $\Sigma ^ n _ {i = 1} \frac{mid}{a_i}$。

如果这个数小于 $k$ 则 $mid$ 减小，反之则增大。

不难发现里面有一些计算重复的数。比如说序列 $(2, 3)$ 其中 $6$ 不是幸运数，$2$ 这里算了一次，$3$ 这里又算了一次，所以个数要 $-2$。所以搞个容斥就行了。

如果集合元素个数为奇数，则加上集合里所有元素的 $lcm \times$ 集合元素个数，否则减去。

由于 $N \leq 15$，所以 $2^N$ 的时间复杂度是安全的（）

by Lightwhite.