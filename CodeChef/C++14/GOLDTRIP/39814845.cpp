#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e4 + 5;
const int MOD = 1e9 + 7;
ll seg_tree[4*N], a[N];

void build(int vertex, int l, int r){
	if(l == r)
		seg_tree[vertex] = a[l];
	else{
		int mid = (l + r) / 2;
		build(2 * vertex, l, mid);
		build((2 * vertex) + 1, mid + 1, r);
		seg_tree[vertex] = seg_tree[2*vertex] + seg_tree[(2*vertex) + 1];
	}
}

ll sum(int vertex, int l, int r, int x, int y){
	if(r < x || l > y) return 0;
	if(x <= l && r <= y)
		return seg_tree[vertex];
	int mid = (l + r) / 2;
	long long int ans = sum(2 * vertex, l, mid, x, y);
	long long int ans1 = sum((2 * vertex) + 1, mid + 1, r, x, y);
	return ans + ans1;
}
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << sum(1, 0, n - 1, a, b) << '\n';
	}
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
