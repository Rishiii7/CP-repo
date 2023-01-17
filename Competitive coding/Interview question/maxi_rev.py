n = 4
m = 4
quantity = [8,8,8,8]
rev = 0
while m > 0 :

    rev += max(quantity)
    index = quantity.index(max(quantity))
    quantity[index] -= 1
    print(index , " : ", quantity)

    m = m - 1

print(rev)