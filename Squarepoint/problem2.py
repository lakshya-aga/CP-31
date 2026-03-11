t = int(input())
for _ in range(t):
    n, rK, cK, rD, cD = map(int, input().split())
    # Distance to nearest corner from Krug
    if rK>rD:
        a = n-rD
    elif rK<rD:
        a = rD
    else:
        a = 0
    if cK>cD:
        b = n-cD
    elif cK<cD:
        b = cD
    else:
        b = 0
    res = max(a, b)
    print(res)
