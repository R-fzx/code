#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 1e5 + 1;

template <typename T>
struct FibNode {
  T v;
  int d;
  FibNode<T> *l, *r, *c, *p;
  bool m;
  FibNode(T _v) : v(_v), d(0), l(this), r(this), c(nullptr), p(nullptr), m(0) {}
};

template <typename T>
struct FibHeap {
  using Node = FibNode<T> *;
  int t, md;
  Node m, *cons;

  FibHeap() {}
  ~FibHeap() {}

  void Insert(T v) {
  }
  void DeleteMin() {
    if (m == nullptr) return;
    Node c = nullptr, _m = m;
    while (_m->c != nullptr) {
      c = _m->c, DeleteNode(c);
      _m->c = (c->r == c ? nullptr : c->r);
      AddNode(c, m), c->p = nullptr;
    }
    RemoveMin();
    if (_m->r == _m) {
      m = nullptr;
    } else {
      m = _m->r, Consolidate();
    }
    --t, delete m;
  }
  void Merge(FibHeap<T> *o) {
    if (o == nullptr) return;
    if (o->md > md) swap(*this, *o);
    if (this->m == nullptr) {
      this->m = o->m, this->t = o->t;
    } else if (o->m != nullptr) {
      MergeList(m, o->m);
      if (m->v > o->m->v) m = o->m;
      t += o->t;
    }
    free(o->cons), delete o;
  }
  bool Min(T *v) {
  }
  void Update(T x, T y) {
  }
  void Delete(T v) {
  }
  bool Contains(T v) {
  }
  void Destroy() {
  }
  void DeleteNode(Node o) { o->l->r = o->r, o->r->l = o->l; }
  void AddNode(Node o, Node r) { o->l = r->l, r->l->r = o, o->r = r, r->l = o; }
  void MergeList(Node x, Node y) {
    Node t;
    t = x->r, x->r = y->r, y->r->l = x, y->r = t, t->l = y;
  }
  void Insert(Node o) {
    if (t++) {
      AddNode(o, m);
      if (o->v < m->v) m = o;
    } else {
      m = o;
    }
  }
  Node RemoveMin() {
    Node p = m;
    if (p == p->r) {
      m = nullptr;
    } else {
      DeleteNode(p), m = p->r;
    }
    return p->l = p->r = p;
  }
  void Link(Node o, Node r) {
    DeleteNode(o);
    if (r->c == nullptr) {
      r->c = o;
    } else {
      AddNode(o, r->c);
    }
    o->p = r, ++r->d, o->m = 0;
  }
  void MakeCons() {
    int o = md;
    md = log2(t) + 1;
    if (o >= md) return;
    cons = (Node *)realloc(cons, sizeof(Node) * (md + 1));
  }
  void Consolidate() {
    MakeCons();
    int _d = md + 1;
    for (int i = 0; i < _d; ++i) cons[i] = nullptr;
    while (m != nullptr) {
      Node x = RemoveMin();
      int d = x->d;
      while (cons[d] != nullptr) {
        Node y = cons[d];
        if (x->v > y->v) swap(x, y);
        Link(y, x), cons[d++] = nullptr;
      }
      cons[d] = x;
    }
    for (int i = 0; i < _d; ++i) {
      if (cons[i] != nullptr) {
        if (m == nullptr) {
          m = cons[i];
        } else {
          AddNode(cons[i], m);
          if (cons[i]->v < m->v) m = cons[i];
        }
      }
    }
  }
  void UpdateDegree(Node o, int d) {
    o->d = d;
    if (o->p != nullptr) UpdateDegree(o->p, d);
  }
  void Cut(Node o, Node p) {
    DeleteNode(o), UpdateDegree(p, o->d);
    p->c = (o == o->r ? nullptr : o->r);
    o->p = nullptr, o->l = o->r = o, o->m = 0, AddNode(o, m);
  }
  void CascadingCut(Node o) {
    Node p = o->p;
    if (p != nullptr) {
      if (!o->m) {
        o->m = 1;
      } else {
        Cut(o, p), CascadingCut(p);
      }
    }
  }
  void DecreaseTo(Node o, T v) {
    Node p;
    if (m == nullptr || o == nullptr) return;
    o->v = v, p = o->p;
    if (p != nullptr && o->v < p->v) Cut(o, p), CascadingCut(p);
    if (o->v < m->v) m = o;
  }
  void IncreaseTo(Node o, T v) {
  }
  void Update(Node o, T v) {
  }
  Node Find(Node r, T v) {
  }
  Node Find(T v) {
  }
  void Delete(Node o) {
  }
  void DestoryNode(Node o) {
  }
};

int main() {
  less<int>()(1, 2);
  return 0;
}