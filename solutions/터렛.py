# solved

N = int(input())
for _ in range(N):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    len = (x1-x2)**2 + (y1-y2)**2
    if (len == 0):
        if (r1 == r2):
            print(-1)
        else:
            print(0)
    else:
        if ((r1-r2)**2 < len < (r1+r2)**2):
            print(2)
        elif (len == (r1-r2)**2 or len == (r1+r2)**2):
            print(1)
        else:
            print(0)