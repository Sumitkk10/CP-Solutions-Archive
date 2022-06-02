#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 2;
long long n, k, b, a[N];
pair<int, int> seg_tree[4 * N];

void build(int vertex, int l, int r){
	if(l == r)
		seg_tree[vertex] = {a[l], l};
	else{
		int mid = (l + r) / 2;
		build(2 * vertex, l, mid);
		build((2 * vertex) + 1, mid + 1, r);
		if(seg_tree[2 * vertex].first >= seg_tree[2 * vertex + 1].first)
			seg_tree[vertex].first = seg_tree[2 * vertex].first, seg_tree[vertex].second = seg_tree[2 * vertex].second;
		else
			seg_tree[vertex].first = seg_tree[2 * vertex + 1].first, seg_tree[vertex].second = seg_tree[2 * vertex + 1].second;
	}
}

pair<ll, ll> max_query(int vertex, int l, int r, int x, int y){
	if(r < x || l > y || l > r) 
		return {0, 0};
	if(x <= l && r <= y)
		return {seg_tree[vertex].first, seg_tree[vertex].second};
	int mid = (l + r) / 2;
	pair<ll, ll> ans = max_query(2 * vertex, l, mid, x, y);
	pair<ll, ll> ans1 = max_query((2 * vertex) + 1, mid + 1, r, x, y);
	if(ans.first >= ans1.first)
		return ans;
	else
		return ans1;
}

void update(int vertex, int l, int r, long long int idx, long long int x){
	if(r < idx || l > idx || l > r) return;
	if(l == r){
		seg_tree[vertex].first = x;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * vertex, l, mid, idx, x);
	update((2 * vertex) + 1, mid + 1, r, idx, x);
	if(seg_tree[2 * vertex].first >= seg_tree[2 * vertex + 1].first){
		seg_tree[vertex].first = seg_tree[2 * vertex].first;
		seg_tree[vertex].second = seg_tree[2 * vertex].second;
	}
	else{
		seg_tree[vertex].first = seg_tree[2 * vertex + 1].first;
		seg_tree[vertex].second = seg_tree[2 * vertex + 1].second;
	}
}


void solve(){
	cin >> n >> k >> b;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long res = 0;
	map<int, int> mp;
	build(1, 0, n - 1);
	vector<int> ans;
	while(k--){
		pair<int, int> mx = max_query(1, 0, n - 1, 0, n - 1);
		if(mp[mx.second] >= b or mx.first <= 0)
			break;
		mp[mx.second]++;
		ans.push_back(mx.second + 1);
		long long sum = ceil((double) mx.first / 3.0);
		res += sum;
		mx.first -= sum;
		update(1, 0, n - 1, mx.second, mx.first);
		if(mp[mx.second] == b)
			update(1, 0, n - 1, mx.second, INT_MIN);
	}
	cout << res << " " << ans.size() << "\n";
	for(auto k : ans)
		cout << k << ' ';
	for(int i = 0; i <= 4 * n; ++i)
		seg_tree[i].first = seg_tree[i].second = 0;
	cout << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}