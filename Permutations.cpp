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
  int n;
  cin >> n;
  if (n == 1)  {
    cout << 1;
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION";
    return 0;
  }
  deque<int> de = {2, 4, 1, 3};
  for (int i = 5; i <= n; i++) {
    if (i%2) de.push_back(i);
    else de.push_front(i);
  }
  for (int i = 0; i < n; i++)
    cout << de[i] << ' ';
  return 0;
}