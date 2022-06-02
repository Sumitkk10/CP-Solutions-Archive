#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int cnt_pos = 0, cnt_odd = 0;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt_pos += (a[i] > 0);
        cnt_odd += (a[i] < 0);
    }
    if(cnt_odd < (n + 1) / 2 and cnt_pos < (n + 1) / 2)
        cout << "0\n";
    else if(cnt_pos > cnt_odd)
        cout << "1\n";
    else
        cout << "-1\n";
}

int main(){
    fast;
    int t = 1;
   //  cin >> t;
    while(t--)
        solve();
    return 0;
}