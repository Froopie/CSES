#include <iostream>
#define ll long long
 
using namespace std;
 
int main() {
  ll n, l = 9, r = 6e17, a;
  cin >> n;
  while (r >= l) {
    ll m = (r+l)>>1;
    ll tot = 0;
    for (ll j = 10; j <= m*10 && tot <= n; j *= 10) {
      tot += ((m+1)/j)*(j/10);
      if ((m+1)%j != 0 && (m%j)/(j/10) >= 1) 
        tot += ((m%j)/(j/10) == 1? m%(j/10)+1 : j/10);
    }
    if (tot > n)
      r = m-1;
    else {
      a = l = m;
      l++;
    }
  }
  cout << a;
}
