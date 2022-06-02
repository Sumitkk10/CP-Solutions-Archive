#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
ll tar;
bool vis[N], yo;

void dfs(int source){
	vis[source] = true;
	if(source == tar) yo = true;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

int main(){
	fast;
	ll n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(!a[i]) tar = i;
		graph[i].push_back(i + a[i]);
		if(i - a[i] >= 0) graph[i].push_back(i - a[i]);
	}
	int c; cin >> c;
	dfs(c);
	if(yo) cout << "true";
	else cout << "false";
	return 0;
}
