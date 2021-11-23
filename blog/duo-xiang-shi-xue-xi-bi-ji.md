# 多项式学习笔记

~~你是否为做不出多项式而苦恼？~~

~~你是否为记不住模板而烦恼？~~

~~到这里，学会最正统的多项式科技！~~

（以上纯属扯淡

## 前置知识

1. 基本数学（复数，多项式，三角函数等）
2. 基本数论

## FFT

大家都知道，手算多项式相乘是很麻烦的，每次都需要算很多次乘法。

那么可以考虑用程序来实现多项式相乘。

我们定义多项式 $f(x)=a_0+a_1x+a_2x^2+a_3x^3\ldots+a_nx^n$。

或者用更数学的方式表示如下：

$$ f(x)=\sum_{i=0}^n f[i]x^i $$
（其中 $f[i]$ 你可以理解为上面的 $a_i$

这样我们要两个多项式相乘怎么表示呢？

设 $C=A\times B$（其中 $A$ 和 $B$ 是多项式

则 $C[k]=\sum\limits_{i=0}^k A[i]B[k-i]$

或者我们换一种形式：$C[k]=\sum\limits_{i+j=k} A[i]B[j]$

而类似与这样形式的 $C[k]=\sum\limits_{i\divideontimes j=k}A[i]B[j]$ 的式子被称为卷积

显然，多项式乘法等价于加法卷积



## NTT

## 求逆

## 求导 & 积分

## ln

## exp

## 快速幂

## 开根

## 除法

## 复合

## 任意模数 NTT

## 多点求值

## 快速插值

## 后记

本文 md 源码达 kB，码字不易，求点赞

推荐 blog：[CYJian](https://www.luogu.com.cn/blog/CYJian/duoxiangshi), [command_block](https://www.luogu.com.cn/blog/command-block/ntt-yu-duo-xiang-shi-quan-jia-tong)
