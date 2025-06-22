N, M = map(int, input().split())
arr = [i for i in range(N+1)]
for i in range(M):
    x, y = map(int, input().split())
    arr[x: y+1] = reversed(arr[x:y+1])

for i in range(N):
    print(arr[i+1], end = ' ')