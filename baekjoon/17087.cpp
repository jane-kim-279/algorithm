/*
https://www.acmicpc.net/problem/17087
백준 숨바꼭질6
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
    int N, S;
    cin >> N >> S;
    int temp = -1;
    while (N--) {
        int A;
        cin >> A;
        int diff = S > A ? S - A : A - S;
        if (temp != -1) temp = gcd(temp, diff);
        else temp = diff;
    }
    cout << temp << '\n';
    return 0;
}
