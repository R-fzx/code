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

  void Insert(T v) { Insert(new FibNode<T>(v)); }
  void DeleteMin() {
    if (m == nullptr) return;
    Node c = nullptr, _m = m;
    while (_m->c != nullptr) {
      c = _m->c, DeleteNode(c);
      _m->c = (c->r == c ? nullptr : c->r);
      AddNode(c, m), c->p = nullptr;
    }
    DeleteNode(_m);
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
  T Min() { return m->v; }
  void Update(T x, T y) {
    Node o = Find(x);
    if (o != nullptr) Update(o, y);
  }
  void Delete(T v) {
    if (m == nullptr) return;
    Node o = Find(v);
    if (o != nullptr) Delete(o);
  }
  bool Contains(T v) { return Find(v) != nullptr; }
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
  void Cut(Node o, Node p) { DeleteNode(o), UpdateDegree(p, o->d), p->c = (o == o->r ? nullptr : o->r), o->p = nullptr, o->l = o->r = o, o->m = 0, AddNode(o, m); }
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
    if (m == nullptr || o == nullptr || o->v == v) return;
    Node p = o->p;
    o->v = v;
    if (p != nullptr && o->v < p->v) Cut(o, p), CascadingCut(p);
    if (o->v < m->v) m = o;
  }
  void IncreaseTo(Node o, T v) {
    if (m == nullptr || o == nullptr || o->v == v) return;
    while (o->c != nullptr) {
      Node c = o->c;
      DeleteNode(c), o->c = (c->r == c ? nullptr : c->r), AddNode(c, m), c->p = nullptr;
    }
    o->d = 0, o->v = v;
    Node p = o->p;
    if (p != nullptr) {
      Cut(o, p), CascadingCut(p);
    } else if (m == o) {
      Node r = o->r;
      while (r != o) {
        if (o->v > r->v) m = r;
        r = r->r;
      }
    }
  }
  void Update(Node o, T v) { v < o.v ? (DecreaseTo(o, v), 0) : (IncreaseTo(o, v), 0); }
  Node Find(Node o, T v) {
    if (o == nullptr) return nullptr;
    Node r = o;
    do {
      if (r->v == v) {
        return r;
      } else {
        Node p = Find(r->c, v);
        if (p != nullptr) return p;
      }
      r = r->r;
    } while (r != o);
    return nullptr;
  }
  Node Find(T v) { return m == nullptr ? nullptr : Find(m, v); }
  void Delete(Node o) { DecreaseTo(o, m->v - 2), DeleteMin(); }
};

FibHeap<int> h;
int q, o, x;

int main() {
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> x;
      h.Insert(x);
    } else if (o == 2) {
      cout << h.Min() << endl;
    } else {
      h.DeleteMin();
    }
  }
  return 0;
}