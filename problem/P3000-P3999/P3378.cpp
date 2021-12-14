#include <iostream>

using namespace std;

template <typename T>
struct PairNode {
  T v;
  PairNode *c, *n, *f;
  PairNode(T _v) : v(_v), c(nullptr), n(nullptr), f(nullptr) {}
};
template <typename T>
using Node = PairNode<T> *;

template <typename T>
Node<T> Create(T v) { return new PairNode<T>(v); }
template <typename T>
Node<T> Merge(Node<T> x, Node<T> y) {
  if (x == nullptr) return y;
  if (y == nullptr) return x;
  if (y->v < x->v) swap(x, y);
  x->f = y->f = nullptr, y->n = x->c;
  if (x->c != nullptr) x->c->f = y;
  x->c = y, y->f = x;
  return x;
}
template <typename T>
Node<T> Insert(Node<T> r, T v) { return Merge(r, Create(v)); }
template <typename T>
Node<T> Merge(Node<T> x) {
  if (x == nullptr || x->n == nullptr) return x;
  x->f = nullptr;
  Node<T> a = x->n, b = nullptr;
  if (a != nullptr) b = a->n, a->n = nullptr;
  x->n = a->f = nullptr;
  return Merge(Merge(x, a), Merge(b));
}
template <typename T>
Node<T> DeleteMin(Node<T> r) { return Merge(r->c); }
template <typename T>
Node<T> Decrease(Node<T> r, Node<T> x, T v) {
  x->v = v;
  if (x->f == nullptr) return x;
  (x->f->c == x ? x->f->c : x->f->n) = x->n;
  x->n->f = x->f, x->n = x->f = nullptr;
  return Merge(r, x);
}

int q, o, x;
Node<int> rt;

int main() {
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> x;
      rt = Insert(rt, x);
    } else if (o == 2) {
      cout << rt->v << endl;
    } else {
      rt = DeleteMin(rt);
    }
  }
  return 0;
}