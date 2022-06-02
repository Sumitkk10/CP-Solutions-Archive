#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int a[N], n, seg_tree[4*N];

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

void solve(){
	cin >> n;
	map<int, vector<int> > pos;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	build(1, 0, n - 1);
	for(int i = 0; i < n; ++i){
		if(pos[a[i]].size() == 1){
			cout << "0 ";
			continue;
		}
		int low = 0, high = pos[a[i]].size() - 1, idx;
		while(low <= high){
			int mid = (low + high) / 2;
			if(pos[a[i]][mid] >= i){
				idx = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		low = idx, high = pos[a[i]].size() - 1;
		int ans = i, res = 0;
		while(low <= high){
			int mid = (low + high) / 2;
			int mx = max_query(1, 0, n - 1, i, pos[a[i]][mid]);
			if(mx <= a[i]){
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		res += (ans - idx);
		low = 0, high = idx;
		while(low <= high){
			int mid = (low + high) / 2;
			int mx = max_query(1, 0, n - 1, pos[a[i]][mid], i);
			if(mx <= a[i]){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		res += (idx - ans);
		cout << res << ' ';
	}
	cout << "\n";
}

int main(){
    fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}