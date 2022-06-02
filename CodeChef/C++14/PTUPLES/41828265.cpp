#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
bool vis[N];
vector<int> primes;
int pre_sum[N];

void sieve(){
    for(int i = 2; i < N; ++i){
        if(!vis[i]){
            for(int j = i; j < N; j += i)
                vis[j] = 1;
            vis[i] = 1;
            primes.push_back(i);
        }
    }
}

void solve(){
    long long int n;
    cin >> n;
    int low = 0, high = primes.size(), ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(primes[mid] <= n){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << pre_sum[ans] << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    sieve();
    for(int i = 2; i <= primes.size(); ++i){
        if(primes[i - 1] == primes[i] - 2)
            pre_sum[i]++;
        pre_sum[i] += pre_sum[i - 1];
    }
    while(t--)
        solve();
    return 0;
}