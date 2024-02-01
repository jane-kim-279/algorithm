/*
  백준 골드바흐의 추측 
  https://www.acmicpc.net/problem/6588
*/

#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int n;
bool ans;
int primeNum[1000001] = {0};

void setPrimeNum() {
    // 소수는 0, 소수가 아닌 경우 1
    for (int i = 2; i * i < 1000000; i++) {
        if (primeNum[i] == 1) continue;
        for (int j = i*i; j <= 1000000; j += i) primeNum[j] = 1;
    }
}

int main() {
    FASTIO
    setPrimeNum();
    while (1) {
        cin >> n;
        if (n==0) break;
        for (int i = 3; i <= n; i += 2) {
            if(primeNum[i] == 0 && primeNum[n-i] == 0) {
                ans = true;
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
        if(!ans) cout << "Goldbach's conjecture is wrong.\n";
    }

}
