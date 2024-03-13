/*
 * 백준 - 토마토 https://www.acmicpc.net/problem/7569
 * 3차원 배열 [깊이][행][열]
*/
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
int m, n, h;
int board[102][102][102];
queue<tuple<int,int,int>> q;
int dx[6] = {1, -1, 0, 0, 0, 0}; 
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main()
{
    FASTIO
    cin >> m >> n >> h;
    for(int k=0;k<h;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    while(!q.empty()) {
        tuple<int,int,int> cur = q.front(); q.pop();
        for(int i=0; i<6; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];
            if(nx<0 || ny<0 || nz<0) continue;
            if(nx>=n || ny>=m || nz>=h) continue;
            if(board[nx][ny][nz] != 0) continue;
            q.push({nx, ny, nz});
            board[nx][ny][nz] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
    int ans = 1;
    for(int k=0;k<h;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                ans = max(board[i][j][k], ans);
            }
        }
    }
    cout << ans - 1;
}
