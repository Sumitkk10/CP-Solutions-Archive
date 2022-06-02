#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll seg_tree[4*N], a[N], n;

void build(int vertex, int l, int r){
	if(l == r)
		seg_tree[vertex] = a[l];
	else{
		int mid = (l + r) / 2;
		build(2 * vertex, l, mid);
		build((2 * vertex) + 1, mid + 1, r);
		seg_tree[vertex] = min(seg_tree[2 * vertex], seg_tree[(2 * vertex) + 1]);
	}
}

ll min_query(int vertex, int l, int r, int x, int y){
	if(r < x || l > y || l > r) 
		return INT_MAX;
	if(x <= l && r <= y)
		return seg_tree[vertex];
	int mid = (l + r) / 2;
	long long int ans = min_query(2 * vertex, l, mid, x, y);
	long long int ans1 = min_query((2 * vertex) + 1, mid + 1, r, x, y);
	return min(ans, ans1);
}

bool check(int x){
	vector<int> cnt(n + 2, 0);
	for(int i = 1; i <= n - x + 1; ++i)
		cnt[min_query(1, 1, n, i, i + x - 1)]++;
	for(int i = 1; i <= n - x + 1; ++i)
		if(cnt[i] != 1)
			return false;
	return true;
}

void solve(){
	cin >> n;
	map<int, int> mp;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	build(1, 1, n);
	vector<int> ans(n + 2, 0);
	if(mp.size() == n)
		ans[1] = 1;
	int mn = min_query(1, 1, n, 1, n);
	if(mn == 1)
		ans[n] = 1;
	int low = 2, high = n - 1, where = n + 1;
	while(low <= high){
		int mid = (low + high) / 2;
		// cout << mid << ' ';
		if(check(mid)){
			where = min(where, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	for(int i = where; i < n; ++i)
		ans[i] = 1;
	for(int i = 1; i <= n; ++i)
		cout << ans[i];
	cout << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}