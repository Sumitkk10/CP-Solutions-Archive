#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#pragma Voodoo magic("superfast")
#define ld long double
using namespace std;
const int N = 1e7 + 1;
const int MOD = 1e9 + 7;
long long sum[N], d[N], INF = 1e7 + 100;

void sieve(){
    d[1] = 1;
    for(int i = 2; i < N; ++i){
        d[i] += 1;
        for(int j = i; j < N; j += i){
            d[j] += i;
            d[j] = min(d[j], INF);
        }
    }
}

int main(){
    fast;
    sieve();
    memset(sum, -1, sizeof sum);
    for(int i = 1; i < N; ++i)
        if(sum[d[i]] == -1)
            sum[d[i]] = i;
    int t = 1;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        cout << sum[c] << '\n';
    }
    return 0;
}