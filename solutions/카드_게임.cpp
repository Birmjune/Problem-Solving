#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Sol 1) set의 경우, 상수가 매우 커서 시간초과가 나오게 됨. 다른 풀이를 찾아야 함.

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int N, M, K;
//     cin >> N >> M >> K;

//     set<int> s; //M개 수 저장할 set
//     for (int i=0; i<M; i++){
//         int a;
//         cin >> a;
//         s.insert(a);
//     } // O(MlogN)

//     for (int i=0; i<K; i++){
//         int b;
//         cin >> b;
//         auto it = s.upper_bound(b); // 형식 추론
//         cout << *it << "\n";
//         s.erase(it);
//     } //O(KlogN)

//     return 0;
// }

// Sol 2)

