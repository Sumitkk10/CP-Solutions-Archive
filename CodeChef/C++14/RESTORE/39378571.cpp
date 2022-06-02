#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 4e6 + 5;
const int MOD = 1e9 + 7;
vector<int> pr;
map<int, int> mp;
int lp[N];

void sieve(){
	for(int i = 2; i <= N; ++i){
   		if(lp[i] == 0) {
        	lp[i] = i;
        	pr.push_back(i);
    	}
    	for(int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        	lp[i * pr[j]] = pr[j];
	}
}

void solve(){
	int n;
	cin >> n;
	int b[n + 1], a[n + 1] = {0};
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(b[i] == i && a[i] == 0){
			a[i] = pr[cnt];
			++cnt;
		}
		else if(a[i] == 0){
			if(a[b[i]] != 0){
				a[i] = a[b[i]];
				continue;
			}
			a[i] = pr[cnt];
			a[b[i]] = pr[cnt];
			++cnt;
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}

int main(){
	fast;
	sieve();
	int t;
	cin >> t;
	while(t--)
		solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
