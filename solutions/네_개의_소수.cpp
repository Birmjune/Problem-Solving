#include <bits/stdc++.h>
using namespace std;

bool arr[1000001];

int main(void){
    int n;
    cin >> n;

    for (int i = 2; i <= 1000000; i++){
        arr[i] = true;
    }

    for (int i = 2; i <= 1000 ; i++){
        if (arr[i]){
            for (int j = 2 * i; j <= 1000000; j+=i){
                arr[j] = false;
            }
        }
    }

    if (n <= 7) {
        cout << -1;
        return 0;
    }
    else if (n % 2 == 0){
        n -= 4;
        for (int i = 2; i <= n; i++){
            if (arr[i] && arr[n-i]){
                cout << 2 << " " << 2 << " " << i << " " << n-i;
                return 0;
            }
        }
    }
    else {
        n -= 5;
        for (int i = 2; i <= n; i++){
            if (arr[i] && arr[n-i]){
                cout << 2 << " " << 3 << " " << i << " " << n-i;
                return 0;
            }
        }
    }
}