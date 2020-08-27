#include <bits/stdc++.h>
 
using namespace std;
 
long double A[601];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= 6; i++)
    A[i] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 600; j >= 1; j--) {
      A[j] = 0;
      for (int k = max(1,j-6); k <= j-1; k++)
        A[j] += A[k];
    }
  long double ans = 0;
  for (int i = a; i <= b; i++)
    ans += A[i];
  ans /= pow(6.,n);
  cout << fixed << setprecision(6) << ans;
  return 0;
}