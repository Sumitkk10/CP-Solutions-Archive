#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 10000005;
bool is_prime[N];
long long ans[N];

void solve(){
    int n, k;
    cin >> n >> k;
    long long int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pre[n + 1];
    map<int, int> mp;
    mp[ans[a[1]]] = 1;
    memset(pre, -1, sizeof pre);
    for(int i = 2; i <= n; ++i){
        if(mp[ans[a[i]]] != 0)
            pre[i] = mp[ans[a[i]]];
        mp[ans[a[i]]] = i;
    }
    long long res = 1, ok = 0;
    for(int i = 2; i <= n; ++i){
        if(pre[i] >= ok){
            ok = i;
            ++res;
        }
    }
    cout << res << "\n";
}

void compute(){
    for(long long i = 2; i < N; ++i){
        if(!is_prime[i]){
            for(long long j = i; j < N; j += i){
                is_prime[j] = true;
                while((ans[j] % (i * i)) == 0)
                    ans[j] /= (i * i);
            }
        }
    }
}

int main() {
    fast;
    for(int i = 0; i < N; ++i)
        ans[i] = i;
    compute();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}