# 浅谈字符串

## 定义与约定

默认以 $s_0$ 为字符串第一位，$s_{|s|-1}$ 为字符串最后一位

字符集用 $\Sigma$ 表示，通常是 $26$ 个小写字母

$\epsilon$ 表示空串

子串 $s_{i\cdots j}$ 表示从 $s_i$ 到 $s_j$ 组成的字符串

前缀 $\operatorname{pre}(s,i)=s_{0\cdots i}$，后缀 $\operatorname{suf}(s,i)=s_{i\cdots |s|-1}$

真前缀和前缀类似，但是不包含 $s$ 本身，真后缀同理

特别的，$\operatorname{pre}(s,-1)=\operatorname{suf}(s,|s|)=\epsilon$

## $\mathrm{I}$ 周期与 $\mathtt{border}$

若存在 $0<p\le|s|$ 满足对于所有 $0\le i<|s|-p$ 有 $s_i=s_{i+p}$，那么我们称 $p$ 是 $s$ 的周期

人话：若 $s$ 为它的某个前缀复制若干份后的子串，那么这个前缀的长度就是 $s$ 的周期

例子：$\mathtt{aababaa}$ 的周期有 $5$（$\mathtt{aabab}$）和 $7$（$\mathtt{aababaa}$）

注意 $s$ 的周期不一定要整除 $|s|$，并且周期不唯一

---

若存在 $0\le p<|s|$ 满足 $\operatorname{pre}(s,p-1)=\operatorname{suf}(s,|s|-p)$，那么 $\operatorname{pre}(s,p-1)$ 为 $s$ 的 $\mathtt{border}$。

人话：若 $s$ 的某个真前缀等于 $s$ 的某个后缀，那么 $s$ 的那个前缀就是 $s$ 的 $\mathtt{border}$

注意 $\mathtt{border}$ 不唯一

例子：$\mathtt{aababaa}$ 的 $\mathtt{border}$ 有 $\mathtt{aa}$，$\epsilon$

---

有性质 $\operatorname{pre}(s,p)$ 是 $s$ 的 $\mathtt{border} \iff |s|-p$ 是 $s$ 的周期

画个图就很显然了：

![4.jpg](https://s2.loli.net/2022/10/19/hAv5opuGfSk4VQB.jpg)

## $\mathrm{II}$ 前缀函数与 $\mathtt{KMP}$ 算法

前缀函数 $\pi(s,i)=\operatorname{pre}(s,i)\text{ 的最长 }\mathtt{border}\text{ 长度}$

$\mathtt{KMP}$ 算法由 Knuth、Pratt 和 Morris 在 1977 年共同发布
