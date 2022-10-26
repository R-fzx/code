import os
from random import *


def generate(In, Out, Id):
    if Id <= 2 * 2:
        n = randint(2, 18); 
        a = [(randint(0, 40), randint(0, 40)) for i in range(1, n + 1)]
    elif Id <= 4 * 2:
        n = randint(1000 - 20, 1000); 
        a = [(randint(0, 981), randint(0, 926)) for i in range(1, n + 1)]
    elif Id <= 7 * 2:
        n = randint(100000 - 20, 100000); 
        a = [(randint(0, n // 10), 0) for i in range(1, n + 1)]
    else: 
        n = randint(100000 - 20, 100000); 
        a = [(randint(0, int(1e9)), randint(0, int(1e9))) for i in range(1, n + 1)]

    print("Processing %d" % Id)
    f = open(In, "w")
    f.write("%d\n" % n)
    for x, y in a: f.write("%d %d\n" % (x, y))
    f.close()
    os.system("./std < %s > %s" % (In, Out))

for Id in range(1, 21):
    s = str(Id) + ".in"
    t = str(Id) + ".out"
    generate(s, t, Id)
