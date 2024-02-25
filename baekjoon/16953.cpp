/*
백준 A -> B
https://www.acmicpc.net/problem/16953
*/

#include <iostream>
#include <queue>
#include <utility>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

long long a, b;
queue<pair<long long, long long>> q;

int bfs(long long a, long long b) {
    q.push(make_pair(a, 1));
    while (!q.empty()) {
        pair<long long, long long> now = q.front();
        q.pop();
        if(now.first == b) return now.second;
        if(now.first*2 <= b) q.push(make_pair(now.first*2, now.second+1));
        if(now.first*10+1 <= b) q.push(make_pair(now.first*10+1, now.second+1));
    }
    return -1;
}

int main() {
    FASTIO
    cin >> a >> b;
    cout << bfs(a, b);
    return 0;
}
