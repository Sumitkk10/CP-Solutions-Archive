#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N], sum[N][2], seg[4*N][2];

void build(int node, int l, int r, int t){
	if(l > r)
		return;
	if(l == r){
		seg[node][t] = sum[l][t];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node, l, mid, t);
	build(2 * node + 1, mid + 1, r, t);
	seg[node][t] = max(seg[2 * node][t], seg[2 * node + 1][t]);
}

int get(int node, int l, int r, int x, int y, int t){
	if(l > r or l > y or r < x)
		return -1e16;
	if(l >= x and r <= y)
		return seg[node][t];
	int mid = (l + r) / 2;
	return max(get(2 * node, l, mid, x, y, t), get(2 * node + 1, mid + 1, r, x, y, t));
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum[i][0] = sum[i - 1][0] + a[i];
	}
	sum[n][1] = a[n];
	for(int i = n - 1; i >= 1; --i)
		sum[i][1] = sum[i + 1][1] + a[i];
	for(int i = 0; i <= 4*n; ++i)
		seg[i][0] = seg[i][1] = -1e16;
	build(1, 1, n, 0);
	build(1, 1, n, 1);
	int nxt_greater[n + 1], prev_greater[n + 1];
	for(int i = 0; i <= n; ++i)
		nxt_greater[i] = n + 1;
	for(int i = 0; i <= n; ++i)
		prev_greater[i] = 0;
	stack<int> st;
	for(int i = 1; i <= n; ++i){
		while(!st.empty() and a[st.top()] < a[i]){
			nxt_greater[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
		st.pop();
	for(int i = n; i >= 1; --i){
		while(!st.empty() and a[st.top()] < a[i]){
			prev_greater[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	for(int i = 1; i <= n; ++i){
		int x = prev_greater[i] + 1, y = nxt_greater[i] - 1;
		// cout << x << ' ' << y << endl;
		int cur = get(1, 1, n, x, i, 1), curr = get(1, 1, n, i, y, 0);
		if(max(curr - sum[i][0], cur - sum[i][1]) > 0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}