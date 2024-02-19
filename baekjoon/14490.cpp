/*
백준 백대열
https://www.acmicpc.net/problem/14490
*/

#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    FASTIO
    //N: 동생 N명, S: 수빈 위치
    int n, m;
    scanf("%d:%d", &n, &m);
    int sub = gcd(n, m);
    cout << n/sub << ":" << m/sub;
    return 0;
}
