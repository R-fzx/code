$$
f(n)=\Theta(g(n)) \to f(n)=g(n)\\
f(n)=O(g(n)) \to f(n)\le g(n)\\
f(n)=o(g(n)) \to f(n)<g(n)\\
f(n)=\Omega(g(n)) \to f(n)\ge g(n)\\
f(n)=\omega(g(n)) \to f(n)>g(n)\\
\\[10px]

T(n)=aT(\frac{n}{b})+f(n)\\
T(n)=
\begin{cases}
  \Theta(f(n)) & f(n)=\Omega(n^c)\ \text{and}\ c>\log_b\!a\\
  \Theta(n^{\log_b\!a}) & f(n)=O(n^c)\ \text{and}\ c<\log_b\!a\\
  \begin{cases}
    \Theta(n^{\log_b\!a}\!\log^{k+1}\!n) & k>-1\\
    \Theta(n^{\log_b\!a}\!\log\log n) & k=-1\\
    \Theta(n^{\log_b\!a}) & k<-1\\
  \end{cases} & f(n)=\Theta(n^{\log_b\!a}\!\log^{k}\!n)\\
\end{cases}
$$
