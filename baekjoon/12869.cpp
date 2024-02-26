/*
백준 뮤탈리스크
https://www.acmicpc.net/problem/12869
*/

#include <iostream>
#include <queue>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

int n;
int hp[3];
int vis[61][61][61];    //vis[a][b][c] = 3: scv의 체력이 각각 a, b, c가 되는데까지 걸린 공격 횟수가 3이다.
struct S{
    int a, b, c;
};
queue<S> q;
int attack[6][3] = {
        {9, 3, 1},
        {9, 1, 3},
        {3, 9, 1},
        {3, 1, 9},
        {1, 9, 3},
        {1, 3, 9},
};

int bfs(int a, int b, int c) {
    vis[a][b][c] = 1;
    q.push({a, b, c});
    while (!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        //모든 scv의 체력이 0인 상태에 도달했다면 break;
        if(vis[0][0][0]) break;
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            //이미 방문했던 곳이면 최단거리가 아니므로 continue;
            if(vis[na][nb][nc]) continue;
            vis[na][nb][nc] = vis[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return vis[0][0][0] - 1;
}

int main() {
    FASTIO
    cin >> n;
    for(int i=0;i<n;i++) cin >> hp[i];
    cout << bfs(hp[0], hp[1], hp[2]);
    return 0;
}
