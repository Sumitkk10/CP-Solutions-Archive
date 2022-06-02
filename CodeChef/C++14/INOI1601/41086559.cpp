#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N], p[N], min_sub[N];
vector<int> tree[N];

void dfs(int source){
	for(auto k : tree[source]){
		if(k != p[source]){ 
			dfs(k);
			min_sub[source] = min(min_sub[source], min(a[source], min_sub[k]));
		}
	}
	min_sub[source] = min(min_sub[source], a[source]);
}

int main(){
	fast;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		min_sub[i] = INT_MAX;
	}
	int root;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		p[i] = x;
		if(x == -1){
			root = i;
			continue;
		}
		tree[x].push_back(i);
		tree[i].push_back(x);
	}
	dfs(root);
	int ans = INT_MIN;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, a[i] - min_sub[i]);
	cout << ans << '\n';
	return 0;
}
