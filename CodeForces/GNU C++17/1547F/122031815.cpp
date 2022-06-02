#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
long long n, a[N], seg_tree[4*N];

void build(int vertex, int l, int r){
	if(l == r)
		seg_tree[vertex] = a[l];
	else{
		int mid = (l + r) / 2;
		build(2 * vertex, l, mid);
		build((2 * vertex) + 1, mid + 1, r);
		seg_tree[vertex] = gcd(seg_tree[2 * vertex], seg_tree[(2 * vertex) + 1]);
	}
}

ll find_gcd(int vertex, int l, int r, int x, int y){
	if(r < x || l > y || l > r) 
		return 0;
	if(x <= l && r <= y)
		return seg_tree[vertex];
	int mid = (l + r) / 2;
	long long int ans = find_gcd(2 * vertex, l, mid, x, y);
	long long int ans1 = find_gcd((2 * vertex) + 1, mid + 1, r, x, y);
	return gcd(ans, ans1);
}

void solve(){
	cin >> n;
	long long res = 0, req;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(i == 1) req = a[i];
		else req = gcd(req, a[i]);
	}
	build(1, 1, n + 1);
	for(int i = 1; i <= n; ++i){
		long long int low = 0, high = n - 1, ans = n;
		while(low <= high){
			int mid = (low + high) / 2;
			long long int how = mid, left = n - i, cur = a[i];
			if(left <= mid){
				cur = find_gcd(1, 1, n + 1, i, n);
				how -= left;
				if(how > 0)
					cur = gcd(cur, find_gcd(1, 1, n + 1, 1, how));
			}
			else
				cur = gcd(cur, find_gcd(1, 1, n + 1, i, i + how));
			if(cur == req){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		res = max(res, ans);
	}
	cout << res << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}