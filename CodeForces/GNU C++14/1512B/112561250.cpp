#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	char a[n][n];
	vector<pair<int, int> > v;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
			if(a[i][j] == '*')
				v.push_back({i, j});
		}
	}
	if(v[0].first != v[1].first and v[0].second != v[1].second){
		a[v[0].first][v[1].second] = '*';
		a[v[1].first][v[0].second] = '*';
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << a[i][j];
			}
			cout << '\n';
		}
		return;
	}
	if(v[0].first == v[1].first){
		if(v[0].first != n - 1){
			a[v[0].first + 1][v[0].second] = '*';
			a[v[1].first + 1][v[1].second] = '*';
		}
		else{
			a[v[0].first - 1][v[0].second] = '*';
			a[v[1].first - 1][v[1].second] = '*';
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << a[i][j];
			}
			cout << '\n';
		}
		return;
	}
	if(v[0].second == v[1].second){
		if(v[0].second != n - 1){
			a[v[0].first][v[0].second + 1] = '*';
			a[v[1].first][v[1].second + 1] = '*';
		}
		else{
			a[v[0].first][v[0].second - 1] = '*';
			a[v[1].first][v[1].second - 1] = '*';
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << a[i][j];
			}
			cout << '\n';
		}
		return;
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
