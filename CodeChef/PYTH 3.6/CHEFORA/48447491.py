sum = []
chefora = [] 
sum.append(0)
chefora.append(0)
n = 100005
q = int(input())
for i in range(1, n):
    if(i <= 9):
        sum.append(sum[i - 1] + i)
        chefora.append(i)
    else:
        s = str(i)
        another_string = ""
        for j in  range(len(s) - 2, -1, -1):
            another_string += s[j]
        s += another_string
        x = int(s)
        sum.append(sum[i - 1] + x)
        chefora.append(x)

for i in range(0, q):
    inp = str(input())
    a = inp.split()
    l = int(a[0])
    r = int(a[1])
    another_string = int(sum[r] - sum[l])
    ans = pow(chefora[l], another_string, 1000000007)
    print(ans)