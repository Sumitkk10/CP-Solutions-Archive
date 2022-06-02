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
	string ans;
	int cur = 0, ct = 0;
	while(cur < n){
		if(ct % 2 == 0 and n - cur != 1){
			cur += 2;
			ans.push_back('2');
		}
		else{
			cur++;
			ans.push_back('1');
		}
		ct++;
	}
	bool ok = 1;
	for(int i = 1; i < ans.size(); ++i){
		if(ans[i] == ans[i - 1])
			ok = 0;
	}
	if(ok){
		cout << ans << '\n';
		return;
	}
	int i = 0, j = 1;
	while(i < ans.size()){
		ans[i] = '1';
		i += 2;
	}
	while(j < ans.size()){
		ans[j] = '2';
		j += 2;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}