#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n, k;
	cin >> n >> k;
	ll nn = n;
	vector<int> fac;
	for(int i = 2; i <= n; ++i){
		int cnt = 0;
		while(n % i == 0 and n > 1){
			fac.push_back(i);
			n /= i;
		}
	}
	if(fac.size() < k)
		cout << "-1\n";
	else{
		for(int i = 1; i < k; ++i)
			cout << fac[i - 1] << ' ';
		ll pro = 1;
		for(int i = k - 1; i < fac.size(); ++i)
			pro *= fac[i];
		cout << pro << '\n';
	}
	return 0;
}
