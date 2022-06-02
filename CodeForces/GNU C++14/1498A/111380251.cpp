#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool poss(long long x){
    string s;
    s = to_string(x);
    long long sum = 0;
    for(auto k : s)
        sum += (k - '0');
    if(__gcd(sum, x) > 1)
        return true;
    return false;
}

void solve(){
    long long n;
    cin >> n;
    for(long long int i = n; i <= n + 10; ++i){
        if(poss(i)){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}