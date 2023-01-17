t1 = 3
t2 = 7
p = 102

min = int(1e7)

print(min)

for i in range(p // t1):
    x = p - t1 * i
    if x % t2 == 0 :
        if (i + x/t2) < min :
            min = (i + x//t2)

for i in range(p // t2):
    x = p - t2 * i
    if x % t1 == 0 :
        if (i + x/t1) < min :
            min = (i + x//t1)

print(min)