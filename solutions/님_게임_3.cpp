#include <bits/stdc++.h>
using namespace std;

int arr[1001]; //arr[i] : initial values

int main() {
    int N, x = 0, ans = 0;
    cin >> N;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        arr[i] = a;
        x = x ^ a; 
    } // result of all xor

    // if 0 : secondary wins, ans: 0
    if (x == 0){
        cout << 0;
        return 0;
    }

    //else: should make the xor value to 0
    int x_ex = 0;
    for (int i=0; i<N; i++){
        x_ex = x ^ arr[i]; //xor value of the values except arr[i]
        if (x_ex < arr[i]) //can make arr[i] to x_ex, xor value = 0
            ans++;
    }
    cout << ans;
    return 0;
}