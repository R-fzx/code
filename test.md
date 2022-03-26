# test

$$
a_{i,j}\\
f(i,j)=\min_{k=1}^m(a_{k,i}+a_{k,j})+\max_{k=1}^m(a_{k,i}+a_{k,j})\\
\text{Solve:}\sum_{i=1}^n\sum_{j=1}^nf(i,j)\\
\begin{aligned}
\text{ans}
&=\sum_{i=1}^n(\sum_{j=1}^n\min_{k=1}^m(a_{k,i}+a_{k,j}))+(\sum_{j=1}^n\max_{k=1}^m(a_{k,i}+a_{k,j}))\\
&=\sum_{i=1}^n\sum_{j=1}^n\min_{k=1}^m(a_{k,i}+a_{k,j})+\sum_{i=1}^n\sum_{j=1}^n\max_{k=1}^m(a_{k,i}+a_{k,j})\\
\end{aligned}
$$
