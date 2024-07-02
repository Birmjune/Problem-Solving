# solved

T = int(input())
same = [[0, 1, 2, 3], [0, 2, 4, 6], [1, 3, 5, 7], [0, 1, 4, 5], [2, 3, 6, 7], [4, 5, 6, 7]]
for i in range(T):
    arr = list(map(int, input().split()))
    arr.sort()
    if arr in same:
        print("YES")
    else:
        print("NO")