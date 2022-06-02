#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int divi[N], ct;

void sieve(){
	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i)
			divi[j]++;
	}
	for(int i = 1; i < N; ++i)
		if(divi[i] % 2)
			++ct;
}

void solve(){
	for(int i = 1; i < N; ++i){
		if(divi[i] % 2){
			cout << i << endl;
			int x;
			cin >> x;
			if(x == 1)
				return;
		}
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	sieve();
	while(t--)
		solve();
	return 0;
}
