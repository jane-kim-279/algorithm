/*
 * 백준 - 나이트의 이동
 * https://www.acmicpc.net/problem/7562
*/
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
#define X first
#define Y second
int t, l;
queue<pair<int, int>> q;
int dist[301][301];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int x, y, xx, yy;
int main() {
    FASTIO
    cin >> t;
    while (t--) {
        cin >> l;cin >> x >> y; cin >> xx >> yy;
        for(int i=0; i<l; i++) fill(dist[i], dist[i] + l, -1);
        dist[x][y] = 0;
        q.push({x, y});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=l || ny>=l) continue;
                if(dist[nx][ny]>=0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dist[xx][yy] << '\n';
    }
}
