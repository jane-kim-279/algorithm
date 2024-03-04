/*
 * BFS 응용2 - 시작점이 여러 개일때
 * 백준 - 토마토 https://www.acmicpc.net/problem/7576
 * BFS를 돌때 큐에 쌓이는 순서는 거리 순일 수 밖에 없다.
 */
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int n, m;
int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main() {
    FASTIO
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) q.push({i, j});    //익은 토마토마다 bfs 돌림
            if(board[i][j] == 0) dist[i][j] = -1;    //익지 않은 토마토 표시
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] >= 0) continue;    //익지 않은 토마토가 아니면 패스
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}
