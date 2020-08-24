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
  multiset<int> s1, s2;
  vector<int> ve; int beg = 0;
  int n, k;
  cin >> n >> k;
  n -= k-1;
  ll tosub = 0, toadd = 0;
  if (k)
  for (int i = 0; i < k-1; i++) {
    int f; cin >> f;
    ve.pb(f);
    if (s1.size() < (k+1)/2) {
      s1.insert(f);
      tosub += 1LL*f;
    }
    else {
      if (*s1.rbegin() > f) {
        tosub -= 1LL*(*s1.rbegin());
        toadd += 1LL*(*s1.rbegin());
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
        s1.insert(f);
        tosub += 1LL*f;
      }
      else {
        s2.insert(f);
        toadd += 1LL*f;
      }
    }
  }
  while (n--) {
    int f; cin >> f;
    ve.pb(f);
    if (s1.empty() || *s1.rbegin() > f) {
      if (s1.size()) {
        tosub -= 1LL*(*s1.rbegin());
        toadd += 1LL*(*s1.rbegin());
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
      }
        s1.insert(f);
        tosub += 1LL*f;
    }
    else {
      s2.insert(f);
      toadd += 1LL*f;
    }
    cout << 1LL*(*s1.rbegin())*((1LL*k+1)/2)-tosub-1LL*(*s1.rbegin())*(1LL*k/2)+toadd << ' ';
    if (ve[beg] > *s1.rbegin()) {
      toadd -= ve[beg];
      s2.erase(s2.find(ve[beg++]));
    }
    else {
      tosub -= ve[beg];
      if (s2.size()) {
        toadd -= 1LL*(*s2.begin());
        s1.insert(*s2.begin());
        tosub += 1LL*(*s2.begin());
        s2.erase(s2.begin());
      }
      s1.erase(s1.find(ve[beg++]));
    }
  }
  return 0;
}