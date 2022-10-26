import os
from random import *


def generate(In, Out, Id):
    if Id == 1:
        n = randint(1, 1)
        a = [randint(0, 15)]
    elif 2 <= Id and Id <= 4: 
        n = randint(4, 5)
        a = [randint(0, 15) for i in range(1, n + 1)]
    elif 5 <= Id and Id <= 10: 
        n = randint(15, 20)
        a = [randint(0, 10 ** 17) for i in range(1, n + 1)]
    elif 11 <= Id and Id <= 14:
        n = randint(99990, 100000)
        a = [2 ** randint(50, 55) - 1] * n; u = a[0]
        for i in range(5, 9):
            v = randint(0, 1)
            if v == 1 and u - (a[0] - 2 ** i) <= 500: 
                a[0] -= 2 ** i
                break
        for i in range(1, n):
            for j in range(9, 56):
                v = [0, 0, 1][randint(0, 2)]
                if v == 1 and a[i] - 2 ** j >= 0: a[i] -= 2 ** j
        shuffle(a)
    elif 15 <= Id and Id <= 20:
        n = randint(99990, 100000)
        a = [randint(0, 10 ** 17) for i in range(1, n + 1)]

    print("Processing %d" % Id)
    f = open(In, "w")
    f.write(str(n)), f.write("\n")
    for i in a: f.write(str(i)), f.write(" ")
    f.close()
    os.system("./std < %s > %s" % (In, Out))

for Id in range(1, 21):
    s = str(Id) + ".in"
    t = str(Id) + ".out"
    generate(s, t, Id)
