#include <iostream>
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll a[MAXN];
int main() {
  int n;
  cin >> n;
  a[0] = 1;
  for (int i = 1; i <= n; i++)
    a[i] = (i*a[i-1] + (i%2? -1 : 1))%mod;
  cout << a[n];
}