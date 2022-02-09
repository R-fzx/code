#include <concepts>
#include <iostream>

using namespace std;

template <class T>
concept myConcept = integral<T> && !same_as<T, bool>;

template <myConcept T>
constexpr void func(T x) {
  // somethingdafds
}

int main() {
  cout << "Hello!";
  return 0;
}