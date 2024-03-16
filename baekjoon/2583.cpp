/*
 * 백준 - 영역 구하기 https://www.acmicpc.net/problem/2583
 * "간격"..
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int m, n, k, cnt;
int board[102][102];
int area[102];
queue<pair<int,int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int bfs() {
    int cnt = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(board[nx][ny]) continue;
            q.push({nx, ny});
            cnt++;
            board[nx][ny] = 1;
        }
    }
    return cnt;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> m >> n >> k;
    while(k--) {
        int x, xx, y, yy;
        cin >> y >> x >> yy >> xx;
        for (int i = x; i < xx; i++) {
            for (int j = y; j < yy; j++) {
                board[i][j] = 1;
            }
        }
    }
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if(!board[i][j]) {
                q.push({i, j});
                area[cnt++] = bfs();
                if(!area[cnt-1])    //bfs 결과가 0이면 1로 바꿔줌..
                    area[cnt - 1] = 1;
            }
        }
    }
    sort(area, area + cnt);
    cout << cnt << '\n';
    for(int i=0; i<cnt; i++) cout << area[i] << ' ';
}
