#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define all(c) c.begin(), c.end()
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define fi first
#define se second
#define M(l,r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
 
struct node{
  ll x;
  node *l, *r; 
};
 
node *newN(ll v=0) {
  node *x = new node;
  x->x = v;
  x->l = x->r = NULL;
  return x;
}
 
node* arr[MAXN];
int cur;
 
void build(node *root, int l, int r) {
  if (l == r) return;
  root->l = newN();
  root->r = newN();
  build(root->l, l, M(l,r));
  build(root->r, M(l,r)+1, r);
}
 
node *upd(node *root, int l, int r, int i, ll x) {
  if (l > i || r < i) return root;
  node *newR = newN();
  if (l == r) {
    newR->x = x;
    return newR;
  }
  newR->l = upd(root->l,l,M(l,r),i,x);
  newR->r = upd(root->r,M(l,r)+1,r,i,x);
  newR->x = newR->l->x + newR->r->x;
  return newR;
}
 
ll gets(node *root, int l, int r, int i, int j) {
  if (l > j || r < i) return 0;
  if (l >= i && r <= j) return root->x;
  return gets(root->l,l,M(l,r),i,j)+gets(root->r,M(l,r)+1,r,i,j);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  arr[0] = newN(); cur = 1;
  build(arr[0],1,n);
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    arr[0] = upd(arr[0],1,n,i,x);
  }
  while (q--) {
    int t, k, a, b;
    ll x;
    cin >> t;
    if (t == 1) {
      cin >> k >> a >> x;
      arr[k-1] = upd(arr[k-1],1,n,a,x);
    } else if (t == 2) {
      cin >> k >> a >> b;
      cout << gets(arr[k-1],1,n,a,b) << '\n';
    } else {
      cin >> k;
      arr[cur++] = arr[k-1];
    }
  }
  return 0;
}