/*
 * 백준 - 적록색약
 * https://www.acmicpc.net/problem/10026
 */
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
#define X first
#define Y second
int n;
string board[102];
int vis[102][102] = {0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int nor, ab;
void bfs(int x, int y) {
    vis[x][y] = 1;
    queue<pair<int,int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(vis[nx][ny] != 0) continue;
            if(board[nx][ny] == board[cur.X][cur.Y]) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}
int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    //일반인 먼저
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0) {
                nor++;
                bfs(i, j);
            }
        }
    }
    //vis 초기화
    memset(vis, 0, sizeof(vis));
    //R, G 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'R') board[i][j] = 'G';
        }
    }
    //적록색약 (int ab)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0) {
                ab++;
                bfs(i, j);
            }
        }
    }
    cout << nor << ' ' << ab;
}
