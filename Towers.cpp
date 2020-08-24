#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  multiset<int> s;
  int n, k;
  cin >> n;
  while (n--) {
    cin >> k;
    auto m = s.lower_bound(k+1);
    if (m == s.end()) s.insert(k);
    else {
      s.erase(m);
      s.insert(k);
    }
  }
  cout << s.size();
}