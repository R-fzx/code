# 浅谈 C++ 魔法 - template

## 前言

知周所众，C 里面的函数是长这样子的：

```plane
<return-type> <func-name>(<arg1-type> <arg1-name>, <arg2-type> <arg2-name>, ..., <argn-type> <argn-name>) {
  <func-setences>
}
```

那么，怎么用 C 函数实现两个数相加的功能呢？

你可能会觉得很简单，并写出了如下代码：

```c
int add(int x, int y) {
  return x + y;
}
```

这段代码虽然简单，但是有两个问题：

1. `int` 值的溢出，与本文无关，下文不再讨论。
2. 无法扩展，只能处理两个 `int` 类型的数的相加。

对于第二个问题，又有两个方法解决它：

1. 声明许多类似 `add_i,add_l,add_d` 的函数来实现不同类型的数的相加。这种方式扩展性与适配性极差，并且为了满足所有类型都可以使用这个函数，代码量大大增加。
2. 使用宏定义。但是容易引发运算优先级的问题，并且不容易查错。

这时，C++ 带着~~全村的~~希望，给我们带来了一个好东西：重载。

使用重载可以避免方案 1 中大量的函数名，提升了扩展性与适配性，但依然码量极多。

难道，就真的没有希望了吗？

## 模板（templates）

回想一下刚刚的需求，问题出在了哪里？

答案是：需求里的”两个数“是抽象的两个数，可以是任何两个东西，而在代码里我们却将其硬编码下来，变成了不再抽象的实例，这就导致了码量的急剧增多。

有没有什么办法能使得我们不将其硬编码下来呢？

答案似乎已经浮出水面：将抽象的类型也当作是一种类型。

于是，C++ 又带着 `template` 登场了。

`template` 的语法十分简洁，只有短短的一句话：

```cpp
template <type1 arg1, type2 arg2, ..., typen argn>
// 此处是函数或类
```

意义也很简单：在编译期时传入参数，`type` 部分可以是 `typename` 或 `class` 或者其他普通类型，如果是 `typename` 或 `class` 就代表对应的 `arg` 是一个类型。由于在编译期时这些参数就已经知道了，所以我们就可以在函数里使用这些参数。

那么上一节留下来的问题也迎刃而解了：使用 `template` 就可以了。

```cpp
template <typename T>
T add(T x, T y) {
  return x + y;
}
```

到了这里，你可能会觉得这不过是一个小玩具，除了减少代码量之外没有任何其他用途，但下一小节，可能会颠覆你对模板的所有看法。

## SFINAE

SFINAE，全称 Substitution Failure Is Not An Error，即替换失败并非错误。

什么意思呢？