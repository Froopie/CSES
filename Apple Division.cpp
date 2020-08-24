#include <cstdio>
long long n, p[25], i,j, a = 1e12, s,t,h;
int main() {
  scanf("%d", &n);
  for (i = 0 ; i < n ; ++i) {scanf("%d", p + i); s += p[i];}
  for (i = 0 ; i < 1 << n; ++i) {
    t = 0;
    for (j = 0 ; j < n; ++j)
      if ((1<<j)&i) t += p[j];
    h=2*t-s;
    if (h<0) h *= -1;
    if (a > h) a = h;
  }
  printf("%lld", a);
}