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
    int a[2*n];
    for(int i = 0; i < 2*n; ++i)
        cin >> a[i];
    sort(a, a+2*n);
    for(int i = 0; i < n; ++i)
    	cout << a[i] << ' ' << a[i + n] << ' ';
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