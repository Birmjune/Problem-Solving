// solved

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
typedef long long ll;

// 0~9 모두 사용하는 계단 수 (인접한 수 차이 = 1) 의 개수
// 예상: DP

ll dp[101][10][(1<<10)]; // dp[N][i][mask]: N자리, i로 끝나며 mask에서 1인 숫자만 사용한 계단 수의 총 개수

int main(void){
    ll i, N, k, mask;
    cin >> N;
    // 초기화
    for (i = 1; i < 10; i++){
        dp[1][i][1<<i] = 1;
    }

    // N = 1 예외 케이스 처리 
    if (N == 1){
        cout << 0;
        return 0;
    }

    // DP 과정
    for (k = 2; k<=N; k++){
        for (mask = 0; mask < (1<<10); mask++){
            dp[k][0][mask | 1] += dp[k-1][1][mask];
            dp[k][0][mask | 1] %= MAX;
            dp[k][9][mask | 512] += dp[k-1][8][mask];
            dp[k][9][mask | 512] %= MAX;
            for (i = 1; i < 9; i++){
                dp[k][i][mask | (1<<i)] += ((dp[k-1][i-1][mask] + dp[k-1][i+1][mask]) % MAX);
                dp[k][i][mask | (1<<i)] %= MAX;
            }
        }
    }

    // 답 계산 
    ll ans = 0;
    // for (int j = 1; j <= N; j++){
    //     ll ans1 = 0;
    //     for (i = 0; i <= 9; i++){
    //         ans1 += (dp[j][i][(1<<10)-1] % MAX);
    //         // cout << dp[N][i][(1<<10)-1] << ' ';
    //     }
    //     ans += (ans1 % MAX);
    //     cout << ans1 << "\n";
    // }
    for (i = 0; i <= 9; i++){
        ans += (dp[N][i][(1<<10)-1] % MAX);
        // cout << dp[N][i][(1<<10)-1] << ' ';
    }
    // cout << dp[2][8][(1<<9) + (1<<8)] << "\n";
    cout << ans % MAX;
}