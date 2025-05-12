// solved

#include <bits/stdc++.h>
using namespace std;

// 기본 idea: 선분들의 교차관계를 확인한 뒤, 교차하는 경우에는 그래프에서 연결
// 이후 union-find를 활용하여 그룹을 만든다.

typedef struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
}Line;

int par[3000]; //par[i]: 트리로 구현 시 부모 노드
int rk[3000]; //rank[i]: i번 노드가 속한 트리의 대략적인 높이
int size1[3000]; //size1[i]: i번 노드가 부모 노드인 점의 개수

void init(int n){
    for(int i=0; i<n; i++){
        par[i] = i;
        rk[i] = 1;
    } 
}

int find(int v){
    if(v == par[v]) 
        return v;
    return par[v] = find(par[v]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v)    
        return;
    if (rk[u] > rk[v]) 
        swap(u, v);
    par[u] = v;
    if (rk[u] == rk[v]) 
        rk[v]++; //rank 같은 상황에서 하나 추가하면 rank 증가, 아닌 경우 큰 트리의 rank 일정
    return;
}

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c){ //CCW 구현 (ab X bc)
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0)
        return 1;
    if (op == 0)
        return 0;
    return -1;
}

int meet(Line l1, Line l2){ //CCW를 이용하여 판정 
    pair<int, int> p1 = {l1.x1, l1.y1};
    pair<int, int> p2 = {l1.x2, l1.y2};
    pair<int, int> p3 = {l2.x1, l2.y1};
    pair<int, int> p4 = {l2.x2, l2.y2};
    // CCW 계산 
    int ab = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    int cd = CCW(p3, p4, p1) * CCW(p3, p4, p2);
    if (ab == 0 && cd == 0){
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        return (p3<=p2 && p1<=p4);
    }
    return (ab<=0 && cd<=0);
}

int main(void){
    // Line들 받기 
    vector<Line> v;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Line l = {a, b, c, d};
        v.push_back(l);
    }

    //만나면 그래프로 연결
    init(N); // 기본 초기화
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            if (meet(v[i], v[j])){
                merge(i, j);
            }
        }
    }

    //union-find 진행
    int num = 0, m = 0;
    for (int i=0; i<N; i++)
        find(i); // 마지막에 find를 한번 더 해주어야 모든 정점이 부모 노드를 가리킴! (find: 맨 위 조상 찾기 + 그 조상을 par에 설정)
                 // merge 과정에서 find는 직접적인 경로 상의 점만 변경하므로...
    for (int i=0; i<N; i++)
        size1[par[i]]++;
    for (int i=0; i<N; i++){
        if (size1[i] != 0)
            num++;
        if (size1[i] > m)
            m = size1[i];
    }

    cout << num << "\n" << m;
    return 0;
}
