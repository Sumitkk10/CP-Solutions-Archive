#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;

void solve(){
	long long int n, m, x;
	cin >> n >> m >> x;
	long long row = x / n, col = x % n;
	if(col != 0)
		++row;
	if(col == 0)
		col = n;
	long long ans = m * (col - 1);
	cout << ans + row << "\n";
}

int main(){
    fast;
	long long int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}