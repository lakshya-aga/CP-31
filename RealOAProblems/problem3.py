import sys
from itertools import accumulate
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    
    prefix1 = list(accumulate(a, initial=0))
    prefix_consec = [0]*(n+1)

    for i in range(1, n):
        if a[i] == a[i-1]:
            prefix_consec[i+1] = 1
    prefix_consec = list(accumulate(prefix_consec))

    for _ in range(q):
        l, r = map(int, input().split())
        num_1s = prefix1[r] - prefix1[l-1]
        num_consec = prefix_consec[r] - prefix_consec[l]
        cost = num_1s + num_consec
        print(cost)
