/*
백준 단지번호붙이
https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;

const int MAX = 25;
int n;
int map[MAX][MAX] = {0};
int vis[MAX][MAX] = {0};
vector<int> v;
int cnt = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
    vis[y][x] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (map[ny][nx] == 1 && vis[ny][nx] == 0) dfs(ny, nx);
    }
}

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) map[i][j] = str[j] - '0';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && vis[i][j] == 0) {
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
    return 0;
}
