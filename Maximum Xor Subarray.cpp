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
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
 
struct node{
  node *a[2];
  int cnt;
};
 
node *newN() {
  node *c = new node;
  c->cnt = 0;
  return c;
}
 
node *create(node *root) {
  if (root) return root;
  return newN();
}
 
void insert(node *root, int &v, int bit) {
  if (bit == -1) {
    root->cnt++;
    return;
  }
  root->a[(v>>bit)&1] = create(root->a[(v>>bit)&1]);
  insert(root->a[(v>>bit)&1],v,bit-1);
}
 
int find(node *root, int v, int bit) {
  if (bit == -1) return 0;
  if (root->a[!((v>>bit)&1)])
    return (1<<bit)+find(root->a[!((v>>bit)&1)],v,bit-1);
  return find(root->a[((v>>bit)&1)],v,bit-1);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  node *root = newN();
  int pre = 0, maxi = 0;
  insert(root,pre,29);
  for (int i = 0; i < n; i++) {
    cin >> x;
    pre ^= x;
    maxi = max(maxi,find(root,pre,29));
    insert(root, pre, 29);
  }
  cout << maxi;
  return 0;
}
