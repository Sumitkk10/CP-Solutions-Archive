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
	vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    if(a == b) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}