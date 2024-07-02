N, M = map(int, input().split())
S, E = map(int, input().split())

P = [[0] * N for i in range(N)]

for i in range(0, N-1):
    P[i+1][i] = 1/(N-1)
    P[i][i+1] = 1/(N-1)

for i in range(N):
    if (i == 0 or i == N-1):
        P[i][i] = (N-2) / (N-1)
    else:
        P[i][i] = (N-3) / (N-1)

# arrmul of size N * N
def arrmul(A, B, N):
    arr = [[0] * N for i in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                arr[i][j] += A[i][k] * B[k][j]
    return arr
    
# calc P^M
def pow(P, M):
    if (M == 1):
        return P
    if (M % 2 == 0):
        return arrmul(pow(P, M/2), pow(P, M/2), N)
    else:
        return arrmul(pow(P, M-1), P, N)

print(pow(P, M)[E-1][S-1])