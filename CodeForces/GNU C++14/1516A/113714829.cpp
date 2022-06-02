#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	while(k--){
		for(int i = 0; i < n - 1; ++i){
			if(a[i] > 0){
				a[i]--;
				a[n - 1]++;
				break;
			}
		}
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
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