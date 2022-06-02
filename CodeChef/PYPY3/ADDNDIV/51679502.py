t = int(input())
for _ in range(0, t):
    a, b = input().split()
    low = 0
    high = 100
    ok = 0
    while(low <= high):
        mid = int((low + high) / 2)
        x = pow(int(b), mid)
        if((x % int(a)) == 0):
            print("YES")
            ok = 1
            break
        else:
            low = mid + 1
    if(ok == 0):
        print("NO")