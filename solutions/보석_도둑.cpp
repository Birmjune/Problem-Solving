//solved

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 보석을 가격순으로 정렬한 뒤 가격이 높은 것 부터 가능한 최소 무게의 가방에 넣기

typedef struct Jewel{
    ll weight;
    ll cost;
}Jewel;

struct compare{
    bool operator()(const Jewel& s1, const Jewel& s2){
        return s1.cost < s2.cost;
    }
};

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 초기화 
    ll N, K;
    cin >> N >> K;
    priority_queue<Jewel, vector<Jewel>, compare> pq; //cost가 큰 것부터 하나씩 뽑혀 나옴
    for (ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        Jewel j = {a, b};
        pq.push(j); //pq에 원소들 넣기
    }

    multiset<ll> bag; // 삽입, 삭제가 모두 O(logN)
    for (ll i = 0; i < K; i++){
        // 가방 무게 초기화 
        ll x;
        cin >> x;
        bag.insert(x);
    }

    // 가방에서 보석 하나씩 뽑기
    ll ans = 0;
    while (!pq.empty()){ //O(N)
        Jewel j = pq.top(); //O(logN)
        pq.pop(); // 가장 가중치가 높은 가방을 뽑고 pq에서 제거
        if (bag.lower_bound(j.weight) != bag.end()){ // 그 보석을 넣을 수 있는 가방이 존재하면
            ans += j.cost; // 가격을 추가 
            bag.erase(bag.lower_bound(j.weight)); // 사용한 가방을 제거 
        }
    }

    cout << ans;
    return 0;
}