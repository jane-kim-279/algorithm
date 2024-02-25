/*
백준 평범한 배낭
https://www.acmicpc.net/problem/12865
*/

#include <iostream>
#include <vector>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int knapsack(int N, int K, vector<int> &W, vector<int> &V) {
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));   //v[0][0]부터 v[N+1][K+1]까지 전부 0으로 초기화
    //모든 물품에 대해 반복
    for (int i = 1; i <= N; ++i) {
        //물품을 고려하여 배낭의 무게를 1부터 K까지 증가시키며 최대 가치합을 계산
        for (int w = 1; w <= K; ++w) {
            //현재 물품의 무게가 보다 크면, 이 물품을 배낭에 넣을 수 없으므로 이전 단계의 값을 그대로 사용
            if (W[i - 1] > w) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w], dp[i-1][w-W[i-1]] + V[i-1]);
        }
    }
    return dp[N][K];
}

int main() {
    FASTIO
    int N, K;
    cin >> N >> K;
    vector<int> W(N), V(N);
    for (int i = 0; i < N; i++) cin >> W[i] >> V[i];
    cout << knapsack(N, K, W, V) << '\n';
    return 0;
}
