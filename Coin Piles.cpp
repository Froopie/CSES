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
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a,b);
    int diff = a-b;
    a -= diff*2; b -= diff;
    if (b >= 0 && b%3 == 0) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}