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
	ll a[n], odd = 0, even = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		odd += ((i % 2) ? a[i] : 0);
		even += ((i % 2 == 0) ? a[i] : 0);
	}
	if(odd >= even){
		for(int i = 0; i < n; ++i){
			if(i % 2)
				cout << a[i] << ' ';
			else
				cout << "1 ";
		}
	}
	else{
		for(int i = 0; i < n; ++i){
			if(i % 2 == 0)
				cout << a[i] << ' ';
			else
				cout << "1 ";
		}
	}
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
