import random

Start = -20000
Stop = 100000
limit = 10

for i in range(1):
    print(limit,1,sep=' ')
    RandomListOfIntegers = [random.randint(
        Start, Stop) for iter in range(limit)]
    for j in RandomListOfIntegers:
        print(j,end=" ")
    print()
    print(8)


