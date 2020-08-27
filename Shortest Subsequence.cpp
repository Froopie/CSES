#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define pb push_back
 
using namespace std;
 
int main() {
  string a;
  cin >> a;
  set<char> b;
  string ans = "";
  for (int i = 0; i < (int)a.size(); i++) {
    b.insert(a[i]);
    if (b.size() == 4) {
      ans.pb(a[i]);
      b.clear();
    }
  }
  cout << ans;
  string to = "ACGT";
  for (int i = 0; i < 4; i++)
    if (b.find(to[i]) == b.end()) {
      cout << to[i];
      return 0;
    }
}