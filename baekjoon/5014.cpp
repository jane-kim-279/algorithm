/*
 * 백준 스타트링크 https://www.acmicpc.net/problem/5014
*/

#include <bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> dx;
int dist[1000001];
int vis[1000001];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    dx.push_back(U);
    dx.push_back(D * -1);
    q.push(S);
    vis[S] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0; i<2; i++){
            int nx = cur + dx[i];
            if(nx<=0 || nx>F) continue;
            if(vis[nx]) continue;
            q.push(nx);
            vis[nx] = 1;
            dist[nx] = dist[cur] + 1;
        }
    }
    if(vis[G]) cout << dist[G];
    else cout << "use the stairs";
}
