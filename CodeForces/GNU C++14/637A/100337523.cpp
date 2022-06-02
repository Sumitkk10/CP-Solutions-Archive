#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp, cnt;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	int mx = 0;
	for(auto k : mp)
		mx = max(mx, k.second);
	for(int i = 0; i < n; ++i){
		cnt[a[i]]++;
		if(cnt[a[i]] == mx){
			cout << a[i] << ' ';
			return 0;
		}
	}
	return 0;
}
