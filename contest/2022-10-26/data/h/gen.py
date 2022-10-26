import os
from random import *


def generate(In, Out, Id):
    if 1 <= Id and Id <= 2:
        n = randint(1, 10); 
        h = [randint(1, 10) for i in range(1, n + 1)]
        h.sort(reverse = True)
        k = h[0] + h[1] + n - 2
        shuffle(h)
        m = randint(1, 10)
        s = [randint(1, n) for i in range(1, m + 1)]
        ask = [(i, randint(1, h[i - 1])) for i in s]
    elif 3 <= Id and Id <= 6:
        n = randint(990, 1000);
        h = [randint(1, 1000) for i in range(1, n + 1)]
        h.sort(reverse = True)
        k = h[0] + h[1] + n - 2
        shuffle(h)
        m = randint(990, 1000)
    elif 7 <= Id and Id <= 12:
        n = randint(49990, 50000);
        h = [randint(1, 20000) for i in range(1, n + 1)]
        h.sort(reverse = True)
        k = h[0] + h[1] + n - 2
        shuffle(h)
        m = randint(49990, 50000)
    elif 13 <= Id and Id <= 17:
        n = randint(200000 - 10, 200000);
        h = [randint(200000 - 10, 200000)] * n;
        k = min(h[0] + h[1] + n - 2, 200000)
        m = randint(200000 - 10, 200000)
    elif 18 <= Id and Id <= 20:
        n = randint(200000 - 10, 200000);
        h = [randint(1, 200000) for i in range(1, n + 1)]
        h.sort(reverse = True)
        k = min(h[0] + h[1] + n - 2, 200000)
        shuffle(h)
        m = randint(200000 - 10, 200000)
    s = [randint(1, n) for i in range(1, m + 1)]
    ask = [(i, randint(1, h[i - 1])) for i in s]


    print("Processing %d" % Id)
    f = open(In, "w")
    f.write("%d %d\n" % (n, k))
    for i in h: 
        f.write(str(i))
        f.write(" ")
    f.write("\n")
    f.write("%d\n" % m)
    for x, y in ask: 
        f.write(str(x) + " " + str(y))
        f.write("\n")
    f.close()
    os.system("./std < %s > %s" % (In, Out))

for Id in range(1, 21):
    s = str(Id) + ".in"
    t = str(Id) + ".out"
    generate(s, t, Id)
