#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
ll seg_tree[4*N], a[N], n, seg_tree1[4*N];

void build(int vertex, int l, int r){
	if(l == r)
		seg_tree[vertex] = a[l];
	else{
		int mid = (l + r) / 2;
		build(2 * vertex, l, mid);
		build((2 * vertex) + 1, mid + 1, r);
		seg_tree[vertex] = max(seg_tree[2 * vertex], seg_tree[(2 * vertex) + 1]);
	}
}

ll max_query(int vertex, int l, int r, int x, int y){
	if(r < x || l > y || l > r) 
		return 0;
	if(x <= l && r <= y)
		return seg_tree[vertex];
	int mid = (l + r) / 2;
	long long int ans = max_query(2 * vertex, l, mid, x, y);
	long long int ans1 = max_query((2 * vertex) + 1, mid + 1, r, x, y);
	return max(ans, ans1);
}

void build1(int vertex, int l, int r){
	if(l == r)
		seg_tree1[vertex] = a[l];
	else{
		int mid = (l + r) / 2;
		build1(2 * vertex, l, mid);
		build1((2 * vertex) + 1, mid + 1, r);
		seg_tree1[vertex] = min(seg_tree1[2 * vertex], seg_tree1[(2 * vertex) + 1]);
	}
}

ll min_query(int vertex, int l, int r, int x, int y){
	if(r < x || l > y || l > r) 
		return INT_MAX;
	if(x <= l && r <= y)
		return seg_tree1[vertex];
	int mid = (l + r) / 2;
	long long int ans = min_query(2 * vertex, l, mid, x, y);
	long long int ans1 = min_query((2 * vertex) + 1, mid + 1, r, x, y);
	return min(ans, ans1);
}

void solve(){
	cin >> n;
	int b[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	unordered_map<int, vector<int> > mp;
	for(int i = 0; i < n; ++i)
		mp[b[i]].push_back(i);
	unordered_map<int, int> ct;
	int mx = 0;
	vector<int> points;
	for(int i = 0; i < n; ++i){
		mx = max(mx, mp[a[i]][ct[a[i]]]);
		ct[a[i]]++;
		if(mx <= i)
			points.push_back(i);
	}
	memset(seg_tree, 0, sizeof seg_tree);
	for(int i = 0; i <= 4*n; ++i)
	     seg_tree1[i] = INT_MAX;
	build(1, 0, n - 1);
	// for(auto k : points) cout << k << ' ';
	// cout << endl;
	build1(1, 0, n - 1);
	ll ans = 0;
	for(int i = 1; i < points.size(); ++i){
		int l = points[i - 1], r = points[i];
		long long mx = max_query(1, 0, n - 1, l + 1, r);
		long long mn = min_query(1, 0, n - 1, l + 1, r);
		ans += (mx - mn);
	}
    ll xx = max_query(1, 0, n - 1, 0, points[0]);
	ll yy = min_query(1, 0, n - 1, 0, points[0]);
	ans += (xx - yy);
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}