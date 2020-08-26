#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ost se;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    se.insert({i,x});
  }
  while (n--) {
    int p;
    cin >> p;
    cout << se.find_by_order(p-1)->second << ' ';
    se.erase(se.find_by_order(p-1));
  }
  return 0;
}