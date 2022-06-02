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
	vector<long long int> miners, gold;
	for(int i = 0; i < 2 * n; ++i){
		int a, b;
		cin >> a >> b;
		if(a == 0)
			miners.push_back(abs(b));
		else
			gold.push_back(abs(a));
	}
	sort(miners.begin(), miners.end());
	sort(gold.begin(), gold.end());
	int j = 0;
	long double ans = 0; 
	for(int i = 0; i < miners.size(); ++i){
		ans += (long double) sqrt(miners[i]*miners[i] + gold[j]*gold[j]);
		++j;
	}
	cout << fixed << setprecision(10) << ans << "\n";
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
