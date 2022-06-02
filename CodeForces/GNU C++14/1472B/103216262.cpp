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
    int a[n], cnt = 0, cnt1 = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt += (a[i] == 1);
        cnt1 += (a[i] == 2);
    }
    if((cnt + (2 * cnt1)) % 2){
    	cout << "NO\n";
    	return;
    }
    if(cnt % 2){
    	cout << "NO\n";
    	return;
    }
    if(cnt1 % 2 == 1 and cnt % 2 == 0 and cnt > 0){
    	cout << "YES\n";
    	return;
    }
    if(cnt1 % 2){
    	cout << "NO\n";
    	return;
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
