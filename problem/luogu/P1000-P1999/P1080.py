n = int(input())
x, y = map(int, input().split(' ', 1))
a = []
for i in range(0, n):
  a.append(tuple(map(int, input().split(' ', 1))))
a.sort(key=lambda x: x[0] * x[1])
ans = -1
for i in a:
  ans = max(ans, x // i[1])
  x *= i[0]
print(ans)