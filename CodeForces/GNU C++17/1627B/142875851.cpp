#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e3 + 5, MOD = 1e9 + 7;
int n, m;

void solve(){
	cin >> n >> m;
	vector<vector<int> > dis(n + 1, vector<int>(m + 1));
	vector<int> v;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			dis[i][j] = i - 1 + j - 1;
			dis[i][j] = max(dis[i][j], abs(i - 1) + abs(j - m));
			dis[i][j] = max(dis[i][j], abs(i - n) + abs(j - m));
			dis[i][j] = max(dis[i][j], abs(i - n) + abs(j - 1));
			v.pb(dis[i][j]);
		}
	}
	sort(v.begin(), v.end());
	for(auto k : v)
		cout << k << ' ';
	cout << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}