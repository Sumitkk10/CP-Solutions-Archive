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
	string a;
	for(int i = 0; i < n; ++i){
		if(i % 3 == 0)
			a.push_back('a');
		else if(i % 3 == 1)
			a.push_back('b');
		else
			a.push_back('c');
	}
	cout << a << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}