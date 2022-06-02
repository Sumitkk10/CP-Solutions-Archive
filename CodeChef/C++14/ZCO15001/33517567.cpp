#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 400;
ll a[N];

ll Palimdrome(ll l, ll r){
    while(l <= r){
        if(a[l] != a[r])
            return false;
        ++l;
        --r;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    ll dp[n+1], k = 1;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = n-1; i >= 0; --i){
        dp[i] = k;
        ++k;
    }
    dp[n] = 0;
    for(int i = n-1; i >= 0; --i){
        for(int j = i; j < n; ++j){
            if(Palimdrome(i, j)){
                dp[i] = min(dp[i], dp[j+1]+1);
            }
        }
    }
    cout << dp[0];
    return 0;
}

//                                      Dynamic-Programming..!