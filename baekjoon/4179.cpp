/*
 * BFS를 돌때 큐에 쌓이는 순서는 거리 순일 수 밖에 없다.
 * BFS 응용3 - 시작점이 2종류일 때
 * 백준 - 불 https://www.acmicpc.net/problem/4179
 */
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
#define X first
#define Y second
int n, m;
string board[1002];
int dist1[1002][1002];      //불
int dist2[1002][1002];      //지훈
queue<pair<int,int>> q1;    //불
queue<pair<int,int>> q2;    //지훈
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == 'J') {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
            if (board[i][j] == 'F') {
                q1.push({i, j});
                dist1[i][j] = 0;
            }
        }
    }
    //불에 대한 BFS
    while (!q1.empty()) {
        pair<int,int> cur = q1.front(); q1.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx, ny});
        }
    }
    //지훈이에 대한 BFS
    while (!q2.empty()) {
        pair<int,int> cur = q2.front(); q2.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            //범위를 벗어남 == 탈출 성공
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            //불이 먼저 전파된 경우
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
