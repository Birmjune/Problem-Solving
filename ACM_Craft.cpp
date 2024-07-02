#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// idea: 위상정렬을 한 뒤, 그 전에 연결된 건물에 대해 max(소요시간) + 짓고자 하는 건물의 건설시간 으로 update
// 위상정렬
// indegree가 0인 점을 모두 큐에 넣고, 하나씩 빼며 연결된 점의 indegree를 1씩 감소
// 그 과정에서 indegree가 0인 점이 생기면 큐에 넣어준다.

int D[1001]; //D[i] : i번 건물 건설 시간
int indegree[1001]; //indegree[i]: i번 정점으로 들어오는 정점 수
vector<int> graph[1001]; //graph[i] : i번 점에 연결된 정점 집합 (i -> j 인 j들)
bool visited[1001];
vector<int> topologicalsort;
int dp[1001]; //dp[i]: i번 건물 짓는 데 걸리는 시간의 최솟값

void FindCycle(int N){ //위상 정렬  
	queue<int> q;
	for (int i=1; i<=N; i++){
		if (indegree[i] == 0){
			visited[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()){
		int head = q.front();
		topologicalsort.push_back(head);
		q.pop();
		for (int i=0; i<graph[head].size(); i++){
			indegree[graph[head][i]]--;
			if (indegree[graph[head][i]] == 0 && !visited[graph[head][i]]){
				visited[graph[head][i]] = true;
				q.push(graph[head][i]);
			}
		}
	}
	for (int i=1; i<=N; i++){
		if (!visited[i])
			return;
	}
	return;
}


int main(void){
    int T;
    cin >> T;
    while (T--){
        // 전역변수 초기화 
        for (int i = 0; i <= 1000; i++){
            D[i] = 0;
            indegree[i] = 0;
            graph[i].clear();
            visited[i] = false;
            dp[i] = 0;
        }
        topologicalsort.clear();

        // 기본 입력 설정
        int N, K, W;
        cin >> N >> K;
        for (int i = 1; i<=N; i++){
            cin >> D[i];
            dp[i] = D[i]; // 기본 건설 시간으로 초기화
        }
        for (int i = 1; i<=K; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        cin >> W;

        // 위상정렬 진행 -> topologicalsort에 순서대로 저장되어 있음
        FindCycle(N);

        // dp 진행 : 위상 정렬 후 앞에서부터 보며 max값으로 update
        for (int i = 0; i < N; i++){
            for (int j = 0; j < graph[topologicalsort[i]].size(); j++){
                int idx = graph[topologicalsort[i]][j];
                dp[idx] = max(dp[idx], dp[topologicalsort[i]] + D[idx]);
            }
        }
        cout << dp[W] << "\n";
    }
    return 0;
}