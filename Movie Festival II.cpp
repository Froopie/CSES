#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define ll long long
#define x first
#define y second
 
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> ve(n);
  multiset<int> se;
  for (int i = 0; i < n; i++)
    cin >> ve[i].x >> ve[i].y;
  sort(all(ve));
  while (k--) se.insert(0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ve[i].x >= *se.begin()) {
      ans++;
      se.erase(se.begin());
      se.insert(ve[i].y);
    } else if (ve[i].y < *se.rbegin()) {
      se.erase(se.find(*se.rbegin()));
      se.insert(ve[i].y);
    }
  }
  cout << ans;
}