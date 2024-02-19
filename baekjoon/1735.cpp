/*
https://www.acmicpc.net/problem/1735
백준 분수 합 
*/

#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main() {
    FASTIO
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int c, d;
    c = a1 * b2 + a2 * b1;
    d = b1 * b2;

    int e = gcd(c, d);
    cout << c/e << " " << d/e;
    return 0;
}
