#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define x first
#define y second
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll a[MAXN];
map<ll,pair<ll,ll>> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      mp[a[j]+a[i]] = {j+1,i+1};
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (mp.find(x-a[i]-a[j]) == mp.end())
        continue;
      pair<int,int> t = mp[x-a[i]-a[j]];
      set<int> se;
      se.insert(t.x);
      se.insert(t.y);
      se.insert(i+1);
      se.insert(j+1);
      if (se.size() < 4) continue;
      while (se.size()) {
        cout << *se.begin() << ' ';
        se.erase(se.begin());
      }
      return 0;
    }
  cout << "IMPOSSIBLE";
  return 0;
}
