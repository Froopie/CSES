#include <bits/stdc++.h>
#define ll long long
const int M=501;
const int m=1e9+7;
 
using namespace std;
 
int n;
string s;
ll dp[M][M],C[M][M];
 
ll rec(int i,int j) {
  if (i>j) return 1;
  ll &ret=dp[i][j];
  if (ret!=-1) return ret;
  ret = 0;
  for (int k=i+1;k<=j;k+=2) {
    if (s[i]!=s[k]) continue;
    ll a = rec(i+1, k-1),
    b = rec(k+1, j);
    if (!a||!b) continue;
    int s1 = max(0,(k-i-1)/2)+1,
    s2 = max(0,(j-k)/2);
    ret+=((a%m*b%m)%m*C[s1+s2][s1])%m;
    ret%=m;
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n=s.size();
  memset(dp,-1,sizeof dp);
  for (int i=0;i<=500; i++)
    for (int j=0;j<=i;j++)
      if (!i||!j) C[i][j]=1;
      else C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
  cout << rec(0,n-1);
}
