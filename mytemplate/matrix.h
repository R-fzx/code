#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <vector>

template <std::size_t N, typename T = double>
class Vector {
 public:
  using Type = T;
  constexpr static std::size_t size = N;
  using Allocator = std::array<T, N>;

  Vector() = default;
  Vector(const Vector&) = default;
  Vector(Vector&&) = default;
  Vector(T _v) { data_.fill(_v); }
  Vector(const Allocator& _data) : data_(_data) {}
  Vector(Allocator&& _data) : data_(std::move(_data)) {}
  Vector(const std::initializer_list<T>& _data) {
    std::copy(_data.begin(), _data.end(), data_.begin());
  }
  Vector(std::initializer_list<T>&& _data) {
    std::copy(_data.begin(), _data.end(), data_.begin());
  }
  Vector(const std::vector<T>& _data) {
    static_assert(_data.size() == N, "vector size must be N");
    std::copy(_data.begin(), _data.end(), data_.begin());
  }
  Vector(std::vector<T>&& _data) {
    static_assert(_data.size() == N, "vector size must be N");
    std::copy(_data.begin(), _data.end(), data_.begin());
  }

  Vector<N, T>& operator=(const Vector&) = default;
  Vector& operator=(Vector&&) = default;

  const Vector& operator+(const Vector& o) const {

  }
 private:
  std::array<T, N> data_;
};
template <typename T = double>
class Matrix {
};

#endif  // MATRIX_H