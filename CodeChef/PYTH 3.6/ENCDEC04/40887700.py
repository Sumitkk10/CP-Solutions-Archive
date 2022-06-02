for _ in range(int(input())):
    x, y = map(int, input().split())
    ans = 0
    sum = 0
    for i in range(1, 11):
        sum += (y * i) % 10
    div = x // y
    rem = div % 10
    mul = div // 10
    ans += (sum * mul)
    for i in range(1, rem + 1):
        ans += (y * i) % 10
    print(ans)