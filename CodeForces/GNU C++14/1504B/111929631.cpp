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
	string a, b;
	cin >> a >> b;
	int flips[n] = {0}, ct = 0, cnt = 0;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == '0') ++ct;
		else ++cnt;
		if(ct == cnt)
			flips[i] = 1;
	}
	for(int i = 0; i < a.size(); ++i){
		int j = i;
		while(a[j] != b[j])
			++j;
		if(j == i)
			continue;
		--j;
		if((!flips[i - 1] and i != 0) or !flips[j]){
			cout << "NO\n";
			return;
		}
		i = j;
	}
	cout << "YES\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
