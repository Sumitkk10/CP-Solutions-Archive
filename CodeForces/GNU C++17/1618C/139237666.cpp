#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long ok = 0;
	for(int i = 0; i < n; i += 2){
		ok = __gcd(ok, a[i]);
	}
	bool okk = 0;
	for(int i = 1; i < n; i += 2){
		if(a[i] % ok == 0){
			okk = 1;
			break;
		}
	}
	if(!okk){
		cout << ok << '\n';
		return;
	}
	ok = 0;
	for(int i = 1; i < n; i += 2){
		ok = __gcd(ok, a[i]);
	}
	okk = 0;
	for(int i = 0; i < n; i += 2){
		if(a[i] % ok == 0){
			okk = 1;
			break;
		}
	}
	if(!okk){
		cout << ok << '\n';
		return;
	}
	cout << "0\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
