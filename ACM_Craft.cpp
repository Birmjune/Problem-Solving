#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// idea: 위상정렬을 한 뒤, 그 전에 연결된 건물에 대해 max(소요시간) + 짓고자 하는 건물의 건설시간 으로 update
// 위상정렬
// indegree가 0인 점을 모두 큐에 넣고, 하나씩 빼며 연결된 점의 indegree를 1씩 감소
// 그 과정에서 indegree가 0인 점이 생기면 큐에 넣어준다.

int main(void){

}