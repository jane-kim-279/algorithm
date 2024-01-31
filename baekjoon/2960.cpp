/*
  백준 에라토스테네스의 체
  https://www.acmicpc.net/problem/2960
*/

#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int n, k, cnt, ans;  // 구하고자 하는 소수의 범위
int primeNum[1001];

int main() {
    FASTIO
    cin >> n >> k;

    // 배열 초기화
    for (int i = 2; i <= n; i++) {
        primeNum[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (primeNum[j] != 0) {
                primeNum[j] = 0;
                cnt++;
                if (cnt == k) {
                    ans = j;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}
