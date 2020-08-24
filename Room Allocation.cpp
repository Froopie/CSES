#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
struct pt{
  int first, second, i;
  bool operator<(const pt &b) {
    return (first != b.first? first < b.first : second < b.second);
  }
};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  set<pair<int,int>> se;
  pt arr[MAXN];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    arr[i].i = i;
  }
  sort(arr, arr+n);
  int ans[MAXN];
  int t = 2;
  se.insert({arr[0].second,1});
  ans[arr[0].i] = 1;
  for (int i = 1; i < n; i++) {
    auto it = se.upper_bound({arr[i].first, 0});
    if (it == se.begin()) {
      se.insert({arr[i].second, t});
      ans[arr[i].i] = t++;;
    }
    else {
      it--;
      ans[arr[i].i] = it->second;
      se.erase(it);
      se.insert({arr[i].second, ans[arr[i].i]});
    }
  }
  cout <<se.size() << '\n';
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}