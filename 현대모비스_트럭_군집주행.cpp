// unsolved

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000001

vector<pair<int, int>> graph[200001];

// 다익스트라 (https://velog.io/@717lumos 참고)
vector<pair<int, int>> dijkstra(int start, int N) //graph[i]에 저장된 값은 {다음노드, 비용}
{
    vector<pair<int, int>> dist(N + 1);  // 거리를 저장할 리스트 초기화, idx 1 ~ N 사용, 부모 노드까지 저장
    for (int i = 1; i<=N; i++){
        dist[i].first = INF;
        dist[i].second = i;
    }

    priority_queue<pair<int, int>> pq;  // 우선순위 큐 선언

    dist[start].first = 0;  // 시작 노드 거리를 0으로 함
    pq.push({ 0, start });  // 우선순위 큐에 넣기

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first; // 큐에서 꺼내 방문하고 있는 정점의 거리, 작은 거리부터 뽑기 위해 부호 바꿔서 저장함
        int cur_node = pq.top().second;  // 정점의 인덱스(번호)
        // cout << cur_dist << ' ' << cur_node << '\n';
        // for (int i = 1; i<=N; i++){
        //     cout << dist[i].first << ' ' << dist[i].second << ' ';
        // }
        // cout << '\n';
        pq.pop();

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int nxt_node = graph[cur_node][i].first;  // 인접 정점 번호
            int nxt_dist = cur_dist + graph[cur_node][i].second;  // 인접 정점까지 거리

            if ((nxt_dist < dist[nxt_node].first)){  // 지금 계산한 것이 기존 거리값보다 작으면
                dist[nxt_node].first = nxt_dist;  // 거리값 업데이트
                dist[nxt_node].second = cur_node; // 부모 노드 업데이트 (이 과정을 위해 등호도 포함하기)
                pq.push({ -nxt_dist, nxt_node });  // 우선순위 큐에 넣기 (부호 바꿔서 넣기)
            }

            if (nxt_dist == dist[nxt_node].first){ // 기존 거리값과 같으면, cur_node -> nxt_node의 비용이 줄어드는 경우에만 갱신 (graph[cur_node][i].second 와 비교한다)
                int parent1 = dist[nxt_node].second;
                int cost1 = 0;
                for (int j = 0; j < graph[parent1].size(); j++){
                    if (graph[parent1][j].first == nxt_node) // len1 -> i
                        cost1 = graph[parent1][j].second;
                }
                if (cost1 > graph[cur_node][i].second){ // parent -> child의 비용이 줄어드는 경우는
                    dist[nxt_node].first = nxt_dist;  // 거리값 업데이트
                    dist[nxt_node].second = cur_node; // 부모 노드 업데이트 (이 과정을 위해 등호도 포함하기)
                    pq.push({ -nxt_dist, nxt_node });  // 우선순위 큐에 넣기 (부호 바꿔서 넣기)
                }
            }
        }
    }
    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
}

int main(void){
    // input
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int ans = 0;

    // Dijkstra로, 모든 최단경로의 거리 합 * (9/10) 계산, 시간복잡도 O(MlogN)
    vector<pair<int, int>> dist = dijkstra(1, N);
    cout << '\n';
    for (int i=2; i<=N; i++){
        // cout << dist[i].first << ' ' << dist[i].second << '\n';
        ans += dist[i].first * 9 / 10;
    }

    // (1 -> N 의 최단경로에 포함되는 모든 간선의 가중치 합) / 10 계산
    for (int i = 2; i<=N; i++){
        int d = dist[i].second;
        for (int j = 0; j < graph[d].size(); j++){
            if (graph[d][j].first == i) // d -> i
                ans += graph[d][j].second / 10;
        }
    }

    cout << ans;
    return 0;
}