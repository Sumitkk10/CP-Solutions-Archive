#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int k;
	cin >> k;
	cout << pow(2, (int) log2(k)) << '\n';
}	

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
