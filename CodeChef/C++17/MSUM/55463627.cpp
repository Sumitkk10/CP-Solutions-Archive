#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
using namespace std;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	int a[n], zero = 0;
	vector<long long> pos, neg;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] > 0)
			pos.push_back(a[i]);
		else if(a[i] < 0)
			neg.push_back(a[i]);
		else
			++zero;
	}
	long long res = 0, ress = 0;
	for(auto k : pos) res = __gcd(res, k);
	for(auto k : neg) ress = __gcd(ress, abs(k));
	if((pos.size() == 0 or neg.size() == 0) or (pos.size() == 1 and neg.size() == 1 and zero == 0)){
	    cout << res + ress << '\n';
	    return;
	}
	cout << 2 * __gcd(res, ress) << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}