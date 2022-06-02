#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	ll no[n + 1], cnt[n + 1];
	no[0] = cnt[0] = 0;
	for(int i = 1; i <= n; ++i){
		cin >> no[i];
		cnt[i] = no[i];
	}
	ll m;
	cin >> m;
	while(m--){
		int a, b;
		cin >> a >> b;
		int numb = cnt[a];
		cnt[a] = 0;
		if(a - 1 >= 1) cnt[a - 1] += b - 1;
		if(a + 1 <= n) cnt[a + 1] += numb - b;
		// for(int i = 1; i <= n; ++i)
			// cout << cnt[i] << " ";
		// cout << endl;
	}
	for(int i = 1; i <= n; ++i)
		cout << cnt[i] << "\n";
	return 0;
}
