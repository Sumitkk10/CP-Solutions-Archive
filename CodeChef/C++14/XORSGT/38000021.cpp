#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long int findXOR(ll n) {
    long long int mod = n % 4;
    if (mod == 0) 
        return n;
    else if (mod == 1) 
        return 1;
    else if (mod == 2)
        return n + 1;
    else if (mod == 3)
        return 0;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll l, r;
		cin >> l >> r;
		if(l == 0) cout << ((findXOR(r))) << "\n";
		else cout << (((findXOR(l - 1) ^ findXOR(r)))) << "\n";
	}
	return 0;
}
