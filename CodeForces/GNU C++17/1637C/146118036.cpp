#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define F first
#define ll long long
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector<long long> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int odd = 0, even = 0;
    bool edge = 1;
    for(int i = 1; i < n - 1; ++i){
    	if(a[i] != 1)
    		edge = 0;
    }
    if(edge){
    	cout << "-1\n";
    	return;
    }
    if(n == 3 and a[1] % 2 != 0){
    	cout << "-1\n";
    	return;
    }
    long long ans = 0;
    for(int i = 1; i < n - 1; ++i)
    	ans += (a[i] + 1) / 2;
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