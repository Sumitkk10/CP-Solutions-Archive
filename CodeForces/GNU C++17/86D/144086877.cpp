#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, q, block = 450;
long long ans, cnt[N], a[N];

struct node{
	int l, r, ind;
}query[N];

bool cmp(node a, node b){
	if(a.l/block == b.l/block)
		return a.r < b.r;
	return a.l < b.l;
}

void solve(){
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < q; ++i){
		cin >> query[i].l >> query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].ind = i;
	}
	vector<long long> res(q);
	sort(query, query + q, cmp);
	int lptr = 0, rptr = 0;
	for(int i = 0; i < q; ++i){
		// cout << lptr << ' ' << query[i].l << ' ' << rptr << ' ' << query[i].r << endl;
		while(lptr > query[i].l){
			ans -= (cnt[a[lptr - 1]] * cnt[a[lptr - 1]] * a[lptr - 1]);
			cnt[a[lptr - 1]]++;
			ans += (cnt[a[lptr - 1]] * cnt[a[lptr - 1]] * a[lptr - 1]);
			--lptr;
		}
		while(lptr < query[i].l){
			ans -= (cnt[a[lptr]] * cnt[a[lptr]] * a[lptr]);
			cnt[a[lptr]]--;
			ans += (cnt[a[lptr]] * cnt[a[lptr]] * a[lptr]);
			++lptr;
		}
		while(rptr <= query[i].r){
			ans -= (cnt[a[rptr]] * cnt[a[rptr]] * a[rptr]);
			cnt[a[rptr]]++;
			ans += (cnt[a[rptr]] * cnt[a[rptr]] * a[rptr]);
			++rptr;
		}
		while(rptr > query[i].r + 1){
			ans -= (cnt[a[rptr - 1]] * cnt[a[rptr - 1]] * a[rptr - 1]);
			cnt[a[rptr - 1]]--;
			ans += (cnt[a[rptr - 1]] * cnt[a[rptr - 1]] * a[rptr - 1]);
			--rptr;
		}
		res[query[i].ind] = ans;
	}
	for(auto k : res)
		cout << k << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}