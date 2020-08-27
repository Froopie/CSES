#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define double long double
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int a, b;
double dpp[8][8][101];
 
bool border(int i, int j) {
  return min(i,j) == 0 || max(i,j) == 7;
}
 
bool corner(int i, int j) {
  i %= 7;
  j %= 7;
  return i == j && i == 0;
}
 
double recc(int y, int x, int k) {
  if (k == 0) return (y == a && b == x);
  double &ret = dpp[y][x][k];
  if (ret != -1) return ret;
  ret = 0;
  double c = 1/4.;
  if (border(y,x)) c = 1/3.;
  if (corner(y,x)) c = 1/2.;
  for(int f = -1; f <= 1; f++)
    for (int g = -1; g <= 1; g++) {
      if (abs(g)+abs(f) != 1) continue;
      if (min(x+g,y+f) >= 0 && max(y+f,x+g) < 8)
        ret += c*recc(y+f,x+g,k-1);
    }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double ans = 0;
  int k;
  cin >> k;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      double prob = 1;
      a = i; b = j;
      for (int ii = 0; ii < 8; ii++)
        for (int jj = 0; jj < 8; jj++)
          for (int kk = 0; kk < 101; kk++)
            dpp[ii][jj][kk] = -1;
      for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++) {
          if (abs(x-j)+abs(i-y) > k || (abs(x-j)+abs(i-y))%2 != k%2)
            continue;
          double cnt = recc(y,x,k);
          prob *= 1-cnt;
        }
      ans += prob;
    }
  cout << fixed << setprecision(6) << ans;
  return 0;
}