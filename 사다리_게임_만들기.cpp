// solved

#include <bits/stdc++.h>
using namespace std;

double dp[500][10001]; //dp[S][M] : S 시작 M개 가로선 1등 확률 (1등 위치는 고정)

int main(void){
    int N, M, S, E;
    cin >> N >> M >> S >> E;
    S -= 1;
    E -= 1; // to use as index
    for (int i = 0; i < N; i++){
        if (i == E)
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }

    for (int m = 1; m<=M; m++){
        for (int s = 0; s<N; s++){
            if (s == 0)
                dp[s][m] = double(N-2)/double(N-1) * dp[s][m-1] + 1.0/double(N-1) * dp[s+1][m-1];
            else if (s == (N-1))
                dp[s][m] = double(N-2)/double(N-1) * dp[s][m-1] + 1.0/double(N-1) * dp[s-1][m-1];
            else
                dp[s][m] = double(N-3)/double(N-1) * dp[s][m-1] + 1.0/double(N-1) * dp[s+1][m-1] + 1.0/double(N-1) * dp[s-1][m-1];
        }
    }

    // for (int i=0; i<N; i++){
    //     for (int j=0; j<=M; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }

    cout << dp[S][M];
    return 0;
}
