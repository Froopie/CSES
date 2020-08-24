#include <iostream>
 
int main() {
  long long n;
  scanf("%lld", &n);
  while (1) {
    printf("%lld ", n);
    if (n == 1) break;
    if (n&1) n = n*3+1;
    else n /= 2;
  }
}