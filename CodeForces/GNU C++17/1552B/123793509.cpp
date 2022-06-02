#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N][6];

int win(int x, int y){
    int ct = 0;
    for(int i = 1; i <= 5; ++i)
        if(a[x][i] < a[y][i]) ++ct;
    if(ct >= 3) return x;
    return y;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= 5; ++j)
            cin >> a[i][j];
    if(n == 1){
        cout << "1\n";
        return;
    }
    int champ = 1;
    for(int i = 2; i <= n; ++i)
        champ = win(champ, i);
    for(int i = 1; i <= n; ++i){
        if(win(champ, i) != champ){
            cout << "-1\n";
            return;
        }
    }
    cout << champ << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
