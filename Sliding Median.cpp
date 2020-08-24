#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
struct node{
  int p, v, sz;
  node *l, *r;
};
 
node *newN(int k) {
  node *x = new node;
  x->p = (rand()<<10)^rand();
  x->v = k;
  x->sz = 1;
  x->l = x->r = NULL;
  return x;
}
 
pair<node*,node*> split(node *t, int k) {
  if (!t) return {t,t};
  if (t->v >= k) {
    auto p = split(t->l, k);
    t->l = p.second;
    t->sz = 1;
    if (t->r) t->sz += t->r->sz;
    if (t->l) t->sz += t->l->sz;
    return {p.first, t};
  }
  else {
    auto p = split(t->r, k);
    t->r = p.first;
    t->sz = 1;
    if (t->r) t->sz += t->r->sz;
    if (t->l) t->sz += t->l->sz;
    return {t, p.second};
  }
}
 
node *merge(node *l, node *r) {
  if (!l || !r) return (l? l : r);
  if (l->p > r->p) {
    l->r = merge(l->r, r);
    l->sz = 1;
    if (l->r) l->sz += l->r->sz;
    if (l->l) l->sz += l->l->sz;
    return l;
  }
  else {
    r->l = merge(l, r->l);
    r->sz = 1;
    if (r->r) r->sz += r->r->sz;
    if (r->l) r->sz += r->l->sz;
    return r;
  }
}
 
node *insert(node* root, int k) {
  auto a = split(root, k);
  return merge(merge(a.first, newN(k)), a.second);
}
 
node *del(node *root, int k) {
  auto a = split(root, k);
  auto b = split(a.second, k+1);
  return merge(a.first, merge(b.first? merge(b.first->l, b.first->r) : NULL, b.second));
}
 
int kth(node *root, int k) {
  if (k == root->sz-(root->r? root->r->sz : 0)) return root->v;
  if (root->l && root->l->sz+1 > k) return kth(root->l, k);
  return kth(root->r, k-(root->l?root->l->sz : 0)-1);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  node *root = NULL;
  int n, k;
  cin >> n >> k;
  int d = k-1;
  vector<int> ve;
  int beg = 0;
  while (d--) {
    int f; cin >> f;
    ve.pb(f);
    root = insert(root, f);
  }
  n -= k-1;
  if (!k&1) k--;
  while (n--) {
    int f; cin >> f;
    ve.pb(f);
    root = insert(root, f);
    cout << kth(root, (k+1)>>1) << ' ';
    root = del(root, ve[beg++]);
  }
  return 0;
}
