/*
  백준 중복 빼고 정렬하기
  https://www.acmicpc.net/problem/10867
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
using namespace std;
int main() {
    FASTIO
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());   //unique의 반환지점부터 끝까지 erase
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
