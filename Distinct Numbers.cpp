#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> se;
  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    se.insert(k);
  }
  cout << se.size();
  return 0;
}