#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 205;
vector<ll> a[N], semiprime;

void sieve(){
    for(int i = 2; i < N; ++i){
        if(a[i].size() == 0){
            for(int j = i; j < N; j += i){
                a[j].push_back(i);
            }
        }
    }
}

int main(){
    fast;
    ll t;
    cin >> t;
    sieve();
    while(t--){
        ll n, ans = 0;
        cin >> n;
        for(int i = 2; i <= n; ++i){
            int d = 0;
            for(int j = 0; j < a[i].size(); ++j){
                for(int k = j + 1; k < a[i].size(); ++k){
                    if(a[i][j] * a[i][k] == i){
                        ++d;
                        break;
                    }
                }
                if(d > 0)
                    break;
            }
            if(d > 0){
                ll p = n - i;
                d = 0;
                for(int j = 0; j < a[p].size(); ++j){
                    for(int k = j + 1; k < a[p].size(); ++k){
                        if(a[p][j] * a[p][k] == p){
                            ++d;
                            break;
                        }
                    }
                    if(d > 0)
                        break;
                }
                if(d > 0){
                    cout << "YES\n";
                    ++ans;
                    break;
                }   
            }
        }
        if(ans == 0)
            cout << "NO\n";
    }
    return 0;
}