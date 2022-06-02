#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int seg_tree[4*N], a[N];

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


void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build(1, 0, n - 1);
	int suff_mx[n], pre_mx[n];
	suff_mx[n - 1] = a[n - 1], pre_mx[0] = a[0];
	map<int, vector<int> > pos;
	pos[suff_mx[n - 1]].push_back(n - 1);
	for(int i = n - 2; i >= 0; --i){
		suff_mx[i] = max(suff_mx[i + 1], a[i]);
		pos[suff_mx[i]].push_back(i);
	}
	for(int i = 1; i < n; ++i)
		pre_mx[i] = max(pre_mx[i - 1], a[i]);
	for(int i = 0; i < n - 2; ++i){
		if(pos[pre_mx[i]].size() == 0) continue;
		int low = 0, high = pos[pre_mx[i]].size() - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			int mn = min_query(1, 0, n - 1, i + 1, pos[pre_mx[i]][mid] - 1);
			if(mn == pre_mx[i]){
				cout << "YES\n";
				cout << i + 1 << ' ' << pos[pre_mx[i]][mid] - i - 1 << ' ' << n - pos[pre_mx[i]][mid] << '\n';
				return;
			}
			else if(mn < pre_mx[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}