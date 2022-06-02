#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> prime[N];

void sieve(){
	for(int i = 2; i < N; ++i){
		if(!prime[i].size())
			for(int j = i; j < N; j += i)
				prime[j].push_back(i);
	}
}

void solve(){
	long long int n;
	cin >> n;
	long long int a[n + 1];
	unordered_map<int, int> pre, suf;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = n; i > 0; --i){
		int x = a[i];
		for(auto k : prime[x])
			suf[k]++;
	}
	unordered_set<int> s;
	for(int i = 1; i < n; ++i){
		int x = a[i];
		for(auto k : prime[x]){
			pre[k]++;
			suf[k]--;
			if(suf[k])
				s.insert(k);
			else if(s.find(k) != s.end())
				s.erase(k);
		}
		if(!s.size()){
			cout << i << '\n';
			break;
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
