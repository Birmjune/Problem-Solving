// solved

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll CCW(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){ //CCW 구현 (ab X bc)
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0)
        return 1;
    if (op == 0)
        return 0;
    return -1;
}

ll meet(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3, pair<ll, ll> p4){ //CCW를 이용하여 판정 
    // CCW 계산 
    ll ab = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    ll cd = CCW(p3, p4, p1) * CCW(p3, p4, p2);
    if (ab == 0 && cd == 0){
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        return (p3<=p2 && p1<=p4);
    }
    return (ab<=0 && cd<=0);
}

int main(void){
    ll a, b, c, d, e, f, g, h;
    pair<ll, ll> p1, p2, p3, p4;
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    p1 = {a, b};
    p2 = {c, d};
    p3 = {e, f};
    p4 = {g, h};
    cout << meet(p1, p2, p3, p4);
    return 0;
}