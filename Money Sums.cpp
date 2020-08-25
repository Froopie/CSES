#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n;
bool can[MAXN];
set<int> se;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  can[0] = 1;
  while (n--) {
    int c;
    cin >> c;
    for (int i = MAXN-c; i >= 0; i--)
      if (can[i]) {
        can[i+c] = 1;
        se.insert(i+c);
      }
  }
  cout << se.size() << endl;
  while (se.size()) {
    cout << *se.begin() << ' ';
    se.erase(se.begin());
  }
  return 0;
}