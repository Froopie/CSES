#include <bits/stdc++.h>
#define pb insert
 
using namespace std;
 
int main() {
  int x, n;
  cin >> x >> n;
  set<int> s; multiset<int> di;
  s.pb(0); s.pb(x);
  di.pb(x);
  while (n--) {
    int p; cin >> p;
    auto it = s.lower_bound(p);
    int d = *it, e = d-p;
    it--;
    d -= *it; 
    int f = p-*it;
    di.erase(di.find(d));
    di.pb(e); di.pb(f);
    s.pb(p);
    cout << *di.rbegin() << ' ';
  }
  return 0;
}