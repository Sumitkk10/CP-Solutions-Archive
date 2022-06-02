#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define F first
#define S second
#define pb push_back
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k, cur = 0;
	cin >> n >> k;
	vector<vector<int> > a(n + 1, vector<int>(k + 1, 0));
	for(int i = 1; i <= n - 1; i += 2){
		for(int j = 1; j <= k; ++j){
			a[i][j] = ++cur;
			a[i + 1][j] = ++cur;
		}
	}
	if(n & 1){
		++cur;
		for(int j = 1; j <= k; ++j){
			a[n][j] = cur;
			cur += 2;
		}
		cur -= 2;
	}
	if(cur > n*k) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k; ++j){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}