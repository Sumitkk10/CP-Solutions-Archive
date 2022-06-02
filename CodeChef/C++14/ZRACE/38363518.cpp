#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ld a[5];
		for(int i = 0; i < 5; ++i) cin >> a[i];
		for(int i = 0; i < 5; ++i)
			a[i] = 100 / a[i];
		if(a[0] == *min_element(a, a+5)) cout << "Champions\n";
		else cout << "-1\n";
	}
	return 0;
}
