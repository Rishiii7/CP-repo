#example test case
a = "1111"
b = "1111"

min_len = min(len(a), len(b))
carry = '0'
res = ''


a = a[::-1]
b = b[::-1]
#print(min_len, a, b)



for i in range(min_len):
    if a[i] == '1' and b[i] == '1' :
        if carry == '1':
            res += '1'
            carry = '1'
        else :
            res += '0'
            carry = '1'
    elif a[i] == '0' and b[i] == '0':
        if carry == '1':
            res += '1'
            carry = '0'
        else :
            res += '0'
    else:
        if carry == '1':
            res += '0'
            carry = '1'
        else :
            res += '1'


for i in range(min_len, len(a)):
    if a[i] == '1':
        if carry == '1':
            res += '0'
            carry = '1'
        else :
            res += '1'
    else :
        if carry == '1':
            res += '1'
            carry = '0'
        else :
            res += '0'

for i in range(min_len, len(b)):
    if b[i] == '1':
        if carry == '1':
            res += '0'
            carry = '1'
        else :
            res += '1'
    else :
        if carry == '1':
            res += '1'
            carry = '0'
        else :
            res += '0'

if carry == '1':
    res += '1'

res = res[::-1]

# resturn res 