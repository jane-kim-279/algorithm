/*
 * 백준 - 불 https://www.acmicpc.net/problem/5427
*/
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
#define X first
#define Y second
int t, w, h;
string board[1002];
int dist1[1002][1002];  //불
int dist2[1002][1002];  //상근
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    FASTIO
    cin >> t;
    while(t--) {
        bool escape = false;
        cin >> w >> h;
        for(int i=0;i<h;i++) {
            fill(dist1[i], dist1[i]+w, -1);
            fill(dist2[i], dist2[i]+w, -1);
        }
        queue<pair<int,int>> q1;    //불
        queue<pair<int,int>> q2;    //상근
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(board[i][j] == '*') {    //불 위치
                    q1.push({i, j});
                    dist1[i][j] = 0;
                }
                if(board[i][j] == '@') {    //상근이 위치
                    q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }
        //불에 대한 bfs
        while(!q1.empty()) {
            auto cur = q1.front(); q1.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                if(board[nx][ny] == '#' || dist1[nx][ny]>=0) continue;
                q1.push({nx, ny});
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            }
        }
        //상근이에 대한 bfs
        while(!q2.empty() && !escape) {
            auto cur2 = q2.front(); q2.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur2.X + dx[dir];
                int ny = cur2.Y + dy[dir];
                //범위를 벗어남 == 성공
                if(nx<0 || ny<0 || nx>=h || ny>=w) {
                    cout << dist2[cur2.X][cur2.Y] + 1 << '\n';
                    escape = true;
                    break;
                }
                //이미 방문했거나 벽인 경우
                if(dist2[nx][ny]>=0 || board[nx][ny]=='#') continue;
                //불이 먼저 전파된 경우
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur2.X][cur2.Y]+1) continue;
                q2.push({nx, ny});
                dist2[nx][ny] = dist2[cur2.X][cur2.Y] + 1;
            }
        }
        if(!escape) cout << "IMPOSSIBLE\n";
    }
}
