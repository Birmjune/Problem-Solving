# solved

N, M = map(int, input().split())
arr = [i for i in range(N+1)]
for i in range(M):
    x, y = map(int, input().split())
    arr[x], arr[y] = arr[y], arr[x]

for i in range(N):
    print(arr[i+1], end = ' ')