#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N], ct = 1;
vector<int> primes;
map<int, int> pos, isPrime, mp, ok;

void sieve(){
    for(int i = 2; i <= 2750131; ++i){
        if(!isPrime[i]){
            for(int j = i + i; j <= 2750131; j += i)
                isPrime[j] = true;
            primes.push_back(i);
            pos[i] = ct;
            ++ct;
        }
    }
}

int fnd(int x){
    int mx = 0;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0)
            mx = max({mx, i, x/i});
    }
    return mx;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= 2*n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a + 1, a + 2*n + 1);
    vector<int> ans;
    for(int i = 2*n; i >= 1; --i){
        if(ok[a[i]]){
            ok[a[i]]--;
            continue;
        }
        if(!isPrime[a[i]]){
            int x = pos[a[i]];
            if(mp[x]){ 
                ans.push_back(x);
                ok[x]++;
            }
            else
                ans.push_back(a[i]);
        }
        else{
            int divi = fnd(a[i]);
            if(mp[divi]){
                ok[divi]++;
                ans.push_back(a[i]);
            }
            else
                ans.push_back(a[i]);
        }
    }
    for(auto k : ans)
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    sieve();
    while(t--)
        solve();
    return 0;
}
