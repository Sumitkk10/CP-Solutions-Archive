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
    if(n <= 10){
        int nn = n, ans = 0;
        while(nn > 1){
            ++ans;
            nn = (nn + 1) / 2;
        }
        cout << ans + (n - 3) << '\n';
        for(int i = 3; i <= n - 1; ++i)
            cout << i << ' ' << i + 1 << '\n';
        nn = n;
        while(nn > 1){
            cout << n << ' ' << 2 << '\n';
            nn = ceil((double) nn / 2);
        }
    }
    else if(n <= 100000){
        int nn = n, ans = 0;
        while(nn > 1){
            ++ans;
            nn = ceil((double) nn / 10);
        }
        cout << n + ans << '\n';
        for(int i = 3; i < 10; ++i)
            cout << i << ' ' << i + 1 << '\n';
        for(int i = 11; i <= n - 1; ++i)
            cout << i << ' ' << i + 1 << '\n';
        nn = n;
        while(nn > 1){
            cout << n << ' ' << 10 << '\n';
            nn = ceil((double) nn / 10);
        }
        int tt = 4;
        while(tt--)
            cout << "10 2\n";
    }
    else{
        int nn = n, ans = 0;
        while(nn > 1){
            ++ans;
            nn = ceil((double) nn / 60);
        }
        cout << n + ans - 4 + 6 << '\n';
        for(int i = 3; i <= 59; ++i)
            cout << i << ' ' << i + 1 << '\n';
        for(int i = 61; i <= n - 1; ++i)
            cout << i << ' ' << i + 1 << '\n';
        nn = n;
        while(nn > 1){
            cout << n << ' ' << 60 << '\n';
            nn = ceil((double) nn / 60);
        }
        int tt = 6;
        while(tt--)
            cout << "60 2\n";
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
