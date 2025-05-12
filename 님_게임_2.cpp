// solved

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x = 0;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        x = x ^ a;
    }
    if (x == 0)
        cout << "cubelover"; //후자 승리
    else 
        cout << "koosaga"; //전자 승리 : 후자의 상황에서 0이 나오게 할 수 있음
    return 0;
}