#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1')
            sum++;
    }
    if(sum <= 1){
        cout << (sum ? "0\n" : "1\n");
        return;
    }
    int mn = n;
    for(int i = 1; i <= n; ++i){
        if(n % i) continue;
        for(int str = 0; str < i; ++str){
            int ans = 0;
            for(int j = str; j < n; j += i){
                if(s[j] == '1') --ans;
                else ++ans;
            }
            mn = min(mn, ans + sum);
        }
    }
    cout << mn << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
