#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll N, n, x;
	cin >> N >> n >> x;
	while(n--){
		x--;
		if(x == 0) x = N;
	}
	cout << x << "\n";
	return 0;
}
