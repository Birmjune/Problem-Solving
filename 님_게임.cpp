#include <bits/stdc++.h>
using namespace std;

//koosaga 전자, codelover 후자, 마지막 돌 제거하면 패배 - 그냥 xor로 간단히 계산 불가 (0을 만들면 패배하므로)
//xor 값이 0 -> not 0, not 0 -> 0과 not 0 둘 다 가능

int main() {
    int N;
    cin >> N;
    int x = 0;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;   
        x = x ^ a;
    }
}