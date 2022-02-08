#include <iostream>
#include <concepts>

using namespace std;

template <class T>
concept myConcept = integral<T> && !same_as<T, bool>;

template<myConcept T>
constexpr void func(T x) {
  // something
}

int main() {

  return 0;
}