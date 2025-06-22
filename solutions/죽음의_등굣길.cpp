// solved

#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
bool visited[100][100];

int distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

bool BFS(int N, int M, int X) {  // (0, 0) 에서 (N-1, M-1) 이동 가능성 확인
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int flag = arr[0][0]; 
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // 도착점에 도달하면 true 반환
        if (x == N - 1 && y == M - 1) {
            return true;
        }
        
        // 갈 수 있는 모든 곳 탐색
        for (int i = -X; i <= X; i++){
            for (int j = -X; j <= X; j++){
                // 다음 좌표로 가능한 점
                int nx = x + i;
                int ny = y + j;
                // 실제로 이동 가능한 점이면 방문 처리 후 큐에 저장
                // 실제 범위 내에 있는지, 이동 가능한 곳인지, 전에 방문한 적은 없는지 확인
                if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && ((abs(i) + abs(j)) <= X) && (arr[nx][ny] == flag) && (!visited[nx][ny])){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return false; // 도착 못하면 false
}


int main() {
    //input
    int N, M, X;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    cin >> X;

    if (arr[0][0] != arr[N-1][M-1]){
        cout << "DEAD";
        return 0;
    }

    if (BFS(N, M, X))
        cout << "ALIVE";
    else
        cout << "DEAD";
        
    return 0;
}