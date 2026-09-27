import random
import sys

sys.stdout = open(".in","w")

n = 810000

res = set(random.sample(range(n),random.randint(500000,n)))
a = [1 if i in res else 0 for i in range(n)]

print(n)
print(*a)
print(n + 3)