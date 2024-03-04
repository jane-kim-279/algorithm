/*
 * BFS 응용1 - 거리 측정
 * 백준 - 미로탐색 https://www.acmicpc.net/problem/2178
 */
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int n, m;
string board[102];
int dist[102][102];
queue<pair<int,int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1);
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1] + 1;
}
