#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n], pos;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int cur = 1;
	while(cur <= n){
		for(int i = 0; i < n; ++i){
			if(a[i] == cur){
				pos = i;
				break;
			}
		}
		if(pos == cur - 1){
			++cur;
			continue;
		}
		for(int i = 0; i < cur - 1; ++i)
			cout << a[i] << ' ';
		for(int i = pos; i >= cur - 1; --i)
			cout << a[i] << ' ';
		for(int i = pos + 1; i < n; ++i)
			cout << a[i] << ' ';
		break;
	}
	if(cur == n + 1)
		for(int i = 0; i < n; ++i)
			cout << i + 1 << ' ';
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}