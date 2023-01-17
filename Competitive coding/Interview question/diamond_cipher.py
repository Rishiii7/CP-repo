# Diamond Cipher
mat = [[]]

res = []

for i in range( (len(mat) - 1 ) // 2 + len(mat[0])):
    new = []
    res.append(new)

#print(res[0], res [1])

#diamond printing
for i in range(len(mat)):
    j = i // 2
    k = 0 
    while k < len(mat[i]):
        res[j].append(mat[i][k])
        k += 1
        j += 1

#reverse
#for i in range(len(res)):
#    res[i] = res[i][::-1]

res_final = []
for i in range(len(mat)):
    j = i // 2
    k = 0
    new = []
    while k < len(mat[i]):
        new.append(res[j].pop())
        k += 1
        j += 1
    res_final.append(new)

# return res_final