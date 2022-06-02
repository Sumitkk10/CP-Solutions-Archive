#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool is_beautiful(int n){
	if ((n&(n>>1)) > 0) return false;
	return true;
}

void solve(){
	int n;
	cin >> n;
	while(!is_beautiful(n))
		--n;
	cout << n << '\n';
}	

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
