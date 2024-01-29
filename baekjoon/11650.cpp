/*
  https://www.acmicpc.net/problem/11650
  백준 좌표 정렬하기 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;
int N;
vector<pair<int, int>> vec;
int main(void) {
    FASTIO
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < N; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
}
