#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
string a[8];
 
int rec(int j, int vert, int diagup, int diagdown) {
  if (j == 8) return 1;
  int ret = 0;
  for (int i = 0; i < 8; i++) {
    if (a[i][j] == '*' || (diagup&(1<<i))
      || (diagdown&(1<<i)) || (vert&(1<<i)))
      continue;
    int nvert = vert|(1<<i);
    int ndiagup = diagup|(1<<i);
    int ndiagdown = diagdown|(1<<i);
    ndiagup >>= 1;
    ndiagdown <<= 1;
    if (ndiagdown >= (1<<8)) ndiagdown -= (1<<8);
    ret += rec(j+1,nvert,ndiagup,ndiagdown);
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 8; i++)
    cin >> a[i];
  cout << rec(0,0,0,0);
  return 0;
}