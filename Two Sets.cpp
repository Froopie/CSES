#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int l = 1, r = n;
  vector<int> v1 , v2;
  if (n%4 == 1 || n%4 == 2) {
    cout << "NO";
    return 0;
  }
  if (n%4 == 3) {
    v1 = {1, 2};
    v2 = {3};
    l = 4;
  }
  cout << "YES\n";
  bool a = 0;
  while (l <= r) {
    if (a) {
      v1.pb(l++);
      v1.pb(r--);
    }
    else {
      v2.pb(l++);
      v2.pb(r--);
    }
    a ^= 1;
  }
  cout << v1.size() << '\n';
  for (int i : v1) cout << i << ' ';
    cout << '\n' << v2.size() << '\n';
  for (int i : v2) cout << i << ' ';
  return 0;
}