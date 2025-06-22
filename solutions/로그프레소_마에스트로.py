# solved

N, M, K = map(int, input().split())
infection = list(map(int, input().split()))
infection.sort()
timeset = []

next = [[i] for i in range(N + 1)] # [[0], [1], [2], ....]

for i in range(M):
    t, a, b = map(int, input().split())
    timeset.append([t, [a, b]])

timeset.sort(key = lambda x : -x[0])

for i in range(len(timeset)):
    a = timeset[i][1][0]
    b = timeset[i][1][1]
    next[a] = next[a] + next[b]
    next[a] = list(set(next[a]))

for i in range(1, N + 1):
    next[i].sort()
    # print(next[i])
    if (next[i] == infection):
        print(i)
    