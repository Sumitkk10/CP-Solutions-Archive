#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	if(k > n){
		cout << "NO\n";
		return;
	}
	if(k == n){
		cout << "YES\n";
		for(int i = 1; i <= k; ++i)
			cout << "1 ";
		cout << '\n';
		return;
	}
	if((n - k - 1) % 2){
		cout << "YES\n";
		cout << n - k + 1 << ' ';
		for(int i = 0; i < k - 1; ++i)
			cout << "1 ";
		cout << '\n';
		return;
	}
	if((n - 2*(k - 1)) > 0 and (n - 2*(k - 1)) % 2 == 0){
		cout << "YES\n";
		cout << n - 2*k + 2 << ' ';
		for(int i = 0; i < k - 1; ++i)
			cout << "2 ";
		cout << '\n';
		return;
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}