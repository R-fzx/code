# test

$$
\begin{aligned}
  ans &= \sum_{l=1}^n\sum_{r=l}^nS(l,r)\\
  &= \sum_{l=1}^n\sum_{r=l}^n(sa_r-sa_{l-1})(sb_r-sb_{l-1})\\
  &= \sum_{l=1}^n\sum_{r=l}^nsa_rsb_r-sa_{l-1}sb_r-sa_rsb_{l-1}+sa_{l-1}sb_{l-1}\\
  &= \sum_{l=1}^{n}sab_{l}-sa_{l-1}ssb_{l}-ssa_lsb_{l-1}+sa_{l-1}sb_{l-1}\\
\end{aligned}
$$
