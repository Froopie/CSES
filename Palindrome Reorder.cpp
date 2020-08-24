#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int occ[200];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (char c : s)
    occ[c]++;
  char mid = 'a';
  int cnt = 0;
  string le = "", ri = "";
  for (int i = 'A'; i <= 'Z'; i++) {
    if ((occ[i]&1)) {
      cnt++;
      mid = i;
    }
    if (cnt == 2) {
      cout << "NO SOLUTION";
      return 0;
    }
    while (occ[i] > 1) {
      occ[i] -= 2;
      le.pb(i);
      ri.pb(i);
    }
  }
  reverse(all(ri));
  if (cnt) le.pb(mid);
  cout << le << ri;
  return 0;
}
