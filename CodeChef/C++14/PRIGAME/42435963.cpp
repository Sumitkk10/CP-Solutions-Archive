#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
bool prime[N];
long long primes_till_now[N];

void gen(){
    for(int i = 2; i <= N; ++i) {
        if (prime[i])
            for (int j = i + i; j <= N; j += i)
                prime[j] = false;
        primes_till_now[i] = prime[i] + primes_till_now[i - 1];
    }
}

void solve(){
    int x, y;
    cin >> x >> y;
    if(y >= primes_till_now[x]){
        cout << "Chef\n";
        return;
    }
    cout << "Divyam\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    memset(prime, 1, sizeof prime);
    gen();
    while(t--)
        solve();
    return 0;
}