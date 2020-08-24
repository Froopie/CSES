#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n;
set<int> se;
map<int,int> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> ve(2*n);
  for (int i = 0; i < n; i++) {
    cin >> ve[i] >> ve[i+n];
    mp[ve[i+n]] = ve[i];
  }
  sort(all(ve));
  int maxi = 0;
  for (int k : ve) {
    if (mp.find(k) != mp.end())
      se.erase(mp[k]);
    else {
      se.insert(k);
      maxi = max(maxi, (int)se.size());
    }
  }
  cout << maxi;
  return 0;
}