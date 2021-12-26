#include <bitset>
#include <cctype>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node_base {
  friend class Node;
  int u;

 protected:
  using State = bitset<101>;
  bool null;
  State first, last;
  Node_base() : u(1) {}
  virtual ~Node_base() {}
};

class Node {
  friend Node operator|(const Node&, const Node&);
  friend Node operator&(const Node&, const Node&);
  friend Node closure(const Node&);
  friend Node positive(const Node&);
  shared_ptr<Node_base> b;

 public:
  using State = Node_base::State;
  Node(int l);
  bool nullable() const { return b->null; }
  const State& firstpos() const { return b->first; }
  const State& lastpos() const { return b->last; }

 private:
  Node(const shared_ptr<Node_base>& _b) : b(_b) {}
};

vector<Node::State> __follow;
vector<int> __corres;

class LetterNode : public Node_base {
  friend class Node;
  int l, i;
  LetterNode(int _l) : l(_l), i(__corres.size()) { null = 0, first.set(i), last.set(i); }
};
Node::Node(int l) : b(new LetterNode(l)) { __follow.resize(__follow.size() + 1), __corres.push_back(l); }

class ClosureNode : public Node_base {
  friend class Node;
  friend Node closure(const Node&);
  friend Node positive(const Node&);
  bool p;
  Node x;
  ClosureNode(bool _p, Node _x) : p(_p), x(_x) {
    null = !p || x.nullable(), first = x.firstpos(), last = x.lastpos();
    for (int i = 0; i < __corres.size(); ++i) {
      if (last.test(i)) {
        __follow[i] |= first;
      }
    }
  }
};
inline Node closure(const Node& x) { return shared_ptr<Node_base>(new ClosureNode(0, x)); }
inline Node positive(const Node& x) { return shared_ptr<Node_base>(new ClosureNode(1, x)); }

class BinaryNode : public Node_base {
  friend class Node;

 protected:
  Node l, r;
  BinaryNode(Node _l, Node _r) : l(_l), r(_r) {}
  virtual ~BinaryNode() {}
};

class OrNode : public BinaryNode {
  friend class Node;
  friend Node operator|(const Node&, const Node&);
  OrNode(Node _l, Node _r) : BinaryNode(_l, _r) { null = l.nullable() | r.nullable(), first = l.firstpos() | r.firstpos(), last = l.lastpos() | r.lastpos(); }
};
inline Node operator|(const Node& l, const Node& r) { return shared_ptr<Node_base>(new OrNode(l, r)); }

class CatNode : public BinaryNode {
  friend class Node;
  friend Node operator&(const Node&, const Node&);
  CatNode(Node _l, Node _r) : BinaryNode(_l, _r) {
    null = l.nullable() & r.nullable(), first = l.nullable() ? (l.firstpos() | r.firstpos()) : l.firstpos(), last = r.nullable() ? (l.lastpos() | r.lastpos()) : r.lastpos();
    for (int i = 0; i < __corres.size(); ++i) {
      if (l.lastpos().test(i)) {
        __follow[i] |= r.firstpos();
      }
    }
  }
};
inline Node operator&(const Node& l, const Node& r) { return shared_ptr<Node_base>(new CatNode(l, r)); }

inline void init() { __corres.clear(), __follow.clear(); }
class Parser {
 public:
  Parser(const string& _s) : s(_s), p(s.begin()), l(*p) {}
  Node build() { return expr(); }

 private:
  string s;
  string::iterator p;
  int l;

  Node expr() { return exprrest(term()); }
  Node exprrest(Node x) {
    if (l == '|') {
      match('|');
      return exprrest(x | term());
    }
    return x;
  }
  Node term() { return termrest(cat()); }
  Node termrest(Node x) { return islower(l) || l == '(' || l == '#' ? termrest(x & cat()) : x; }
  Node cat() {
    Node x = single();
    if (l == '*') {
      return match('*'), closure(x);
    } else if (l == '+') {
      return match('+'), positive(x);
    }
    return x;
  }
  Node single() {
    if (islower(l) || l == '#') {
      int x = l;
      match(x);
      return Node(x);
    }
    match('(');
    Node x = expr();
    match(')');
    return x;
  }
  void match(int x) { l = (++p == s.end() ? 0 : *p); }
};

class DFA {
  using State = Node::State;
  static constexpr int kE = 27;
  State s;
  int sc, fsn;
  unordered_map<State, State[kE]> tr;
  unordered_set<State> st;

  int encode(int c) const { return c == '#' ? 26 : c - 'a'; }
  bool isFinal(const State& x) { return x.test(fsn); }
  void build() {
    static queue<State> q;
    st.insert(s), q.push(s);
    while (!q.empty()) {
      State x = q.front();
      q.pop();
      vector<int> v[kE];
      for (int i = 0; i < sc; ++i) {
        if (x.test(i)) {
          v[encode(__corres[i])].push_back(i);
        }
      }
      for (int i = 0; i < kE; ++i) {
        State y;
        for (const auto& j : v[i]) {
          y |= __follow[j];
        }
        if (st.find(y) == st.end()) {
          st.insert(y), q.push(y);
        }
        tr[x][i] = y;
      }
    }
  }

 public:
  DFA(const string& _s) : s(Parser(_s).build().firstpos()), sc(__corres.size()), fsn(sc - 1) { build(); }
  bool match(const string& _s) {
    State o = s;
    for (const auto& i : _s) {
      o = tr[o][encode(i)];
      if (o.none()) {
        return 0;
      }
    }
    return isFinal(o);
  }
};

int main() {
  string p, s;
  while (cin >> p >> s) {
    init();
    cout << (DFA(p + "#").match(s) ? "Yes" : "No") << endl;
  }
}