#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 9; 
const int N = 1e6 + 1;
ll prime[N];

void sieve(){
    prime[1] = 0;
    for(int i = 2; i < N; ++i){
        if(prime[i] == 0){
            prime[i] = 1;
            for(int j = i*2; j < N; j += i){
                prime[j] += 1;
            }
        }
    }
}

int main(){
    fast;
    ll t;
    cin >> t;
    sieve();
    vector<ll> dp[N];
    for(int i = 1; i < N; ++i)
        dp[prime[i]].push_back(i);
    while(t--){
        ll l, r, k;
        cin >> l >> r >> k;
        ll low = 0, high = dp[k].size() - 1, x = 0, y = -1;
        while(low <= high){
            ll mid = (low+high)/2;
            if(dp[k][mid] < l){
                low = mid + 1;
            }
            else{
                x = mid;
                high = mid-1;
            }
        }
        low = 0, high = dp[k].size()-1;
        while(low <= high){
            ll mid = (low+high)/2;
            if(dp[k][mid] > r){
                high = mid-1;
            }
            else{
                y = mid;
                low = mid+1;
            }
        }
        cout << (y-x)+1 << endl;
    }
    return 0;
}