#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<string> ve;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  sort(all(s));
  do {
    ve.pb(s);
  } while (next_permutation(all(s)));
  cout << ve.size() << '\n';
  sort(all(ve));
  for (string cc : ve)
    cout << cc << '\n';
  return 0;
}
