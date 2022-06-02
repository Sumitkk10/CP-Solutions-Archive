#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a == b){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	ans.push_back(a);
	int cur = 1;
	for(int i = n; i > a; --i){
		if(i == b) continue;
		if(cur == n/2)
			break;
		ans.push_back(i);
    ++cur;
	}
	if(cur != n / 2){
		cout << "-1\n";
		return;
	}
	ans.push_back(b);
	cur = 1;
	for(int i = 1; i < b; ++i){
		if(i == a) continue;
		if(cur == n/2) break;
		ans.push_back(i);
    ++cur;
	}
	if(cur != n / 2){
		cout << "-1\n";
		return;
	}
	for(auto k : ans)
		cout << k << ' ';
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