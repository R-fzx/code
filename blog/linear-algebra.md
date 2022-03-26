# 浅谈线性代数

## 前言

本文 `markdown` 源码达 $0\ \text{KB}$，从 2022/3/22 一个偶然的想法一直拖到 2022/3/22。

本人语文不好，尽请谅解。

## 前置知识

- 初中数学

## 符号及约定

## 何为向量

向量，本质上其实就是一串数，你可以把它看作一个空间中的箭头，亦可以看作一个坐标，在本文，我们将其看作是一个起点总在原点的空间中的箭头。一般来说，我们使用
$\begin{bmatrix}
  \vec{\mathbf{v}}_1\\
  \vec{\mathbf{v}}_2\\
  \vdots\\
  \vec{\mathbf{v}}_n\\
\end{bmatrix}$
来表示一个向量，也可以写作 $\vec{\mathbf{v}}$。我们定义向量加法如下：
$$
\vec{\mathbf{v}}+\vec{\mathbf{w}}=
\begin{bmatrix}
  \vec{\mathbf{v}}_1+\vec{\mathbf{w}}_1\\
  \vec{\mathbf{v}}_2+\vec{\mathbf{w}}_2\\
  \vdots\\
  \vec{\mathbf{v}}_n+\vec{\mathbf{w}}_n\\
\end{bmatrix}
$$
对于向量加法，其实有一个很直观的几何解释：对于平面中的两个向量 $\vec{\mathbf{v}}$ 和 $\vec{\mathbf{w}}$，我们将 $\vec{\mathbf{w}}$ 的起点通过平移移到 $\vec{\mathbf{v}}$ 的终点，那么 $\vec{\mathbf{v}}+\vec{\mathbf{w}}$ 就是一个终点在 $\vec{\mathbf{w}}$ 当前终点的一个向量，用图说明就是这样：

![thanks 3b1b](https://s2.loli.net/2022/03/22/X3rnfU1CJGdoD2c.png)

除向量加法外，向量还有另一个基础运算：向量数乘，我们定义向量数乘如下：

$$
c\cdot\vec{\mathbf{v}}=
\begin{bmatrix}
  c\cdot\vec{\mathbf{v}}_1\\
  c\cdot\vec{\mathbf{v}}_2\\
  \vdots\\
  c\cdot\vec{\mathbf{v}}_n\\
\end{bmatrix}
$$
（其中 $c$ 为实数）

至于几何解释，可以简单的看作一个向量 $\vec{\mathbf{v}}$ 被缩放成了原来的 $c$ 倍，图片解释如下：

![image.png](https://s2.loli.net/2022/03/22/Urj8mpCNakgBHf5.png)![image.png](https://s2.loli.net/2022/03/22/iXnyc12Qrgf35WS.png)![image.png](https://s2.loli.net/2022/03/22/FNkf5S9hqJ6UagD.png)

而有时候，向量数乘还有另外一个名字：“缩放”，此时 $c$ 也有了另一个名字：“标量”。

---

$$
\vec{\mathbf{v}}\\
\begin{bmatrix}
  \vec{\mathbf{v}}_1\\
  \vec{\mathbf{v}}_2\\
  \vdots\\
  \vec{\mathbf{v}}_n\\
\end{bmatrix}
$$
