// solved

#include <bits/stdc++.h>
using namespace std;

//주어진 배열의 부분합 배열을 생성 : O(N)
//정렬된 상태이므로, 각 sum[i]에 대해 sum[i] + S 이상인 최소의 idx 발견 : O(NlogN)
//각 상황에서 idx-i 의 최솟값 return : O(logN)
//total: O(NlogN)

//피드백: sum[i] - sum[j] (i>j) 는 arr[0]이 있는 경우 표현 불가, 앞에 0 추가해서 부분합배열 만들자.

int arr[100000];
int sum[100000]; //sum[i] = arr[0] + ... + arr[i]
int diff[100000]; //diff[i]  = idx - is

int main(){
    //get values of arr, sum
    int N, S;
    cin >> N >> S;
    for (int i=0; i<N; i++)
        cin >> arr[i+1];
    arr[0] = 0;
    sum[0] = 0;
    for (int i = 1; i<=N; i++)
        sum[i] = sum[i-1] + arr[i];

    //이분탐색
    int flag = 0;
    for (int i=0; i<=N; i++){
        if (sum[i] + S <= sum[N]){
            diff[i] = lower_bound(sum, sum + N + 1, sum[i] + S) - sum - i;
            flag++;
        }
        else   
            diff[i] = N + 1;
        // cout << diff[i] << "\n";
    }
    if (flag > 0)
        cout << *min_element(diff, diff + N + 1);
    else    
        cout << 0;
    return 0;
}