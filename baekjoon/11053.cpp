/*
 * https://www.acmicpc.net/problem/11053
 * 백준 가장 긴 증가하는 부분 수열
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int main() {
    FASTIO
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> dp(N, 1); //dp[i]: A[i]를 마지막으로 하는 LIS. 1로 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
