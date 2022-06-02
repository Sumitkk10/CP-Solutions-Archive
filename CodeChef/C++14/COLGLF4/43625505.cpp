#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const long long int N = 1e6 + 5;
const long long int MOD = 1e9 + 7;

long long int go(long long n, long long e, long long h, long long a, long long b, long long c){
    if(n <= 0)
        return 0;
    long long ans = 1e12;
    if((2 * n) <= e)
        ans = min(ans, n * a);
    if((3 * n) <= h)
        ans = min(ans, n * b);
    if(n <= min(e, h))
        ans = min(ans, n * c);
    if(((h - n) / 2 >= 1) and ((h - n) / 2 >= n - e)){
        if(b < c){
            long long int ok = min(n - 1, (h - n) / 2);
            ans = min(ans, (b - c) * ok + (n * c));
        }
        else{   
            long long int ok = max(1LL, n - e);
            ans = min(ans, (b - c) * ok + (n * c));
        }
    }
    if((e - n >= 1) and (e - n >= n - h)){
        if(a < c){
            long long int ok = min(n - 1, e - n);
            long long int well = (a - c) * ok + (n * c);
            ans = min(ans, well);
        }
        else{
            long long int ok = max(1LL, n - h);
            ans = min(ans, (a - c) * ok + (n * c));
        }
    }
    if((e / 2 >= 1) and (e / 2 >= (3 * n - h + 2) / 3)){
        if(a < b){
            long long int ok = min(n - 1, e / 2);
            long long int well = (a - b) * ok + (n * b);
            ans = min(ans, well);
        }
        else{
            long long int ok = max(1LL, (3 * n - h + 2) / 3);
            ans = min(ans, (a - b) * ok + (n * b));
        }
    }
    if(e >= 3 and h >= 4 and n >= 3)
        ans = min(ans, a + b + c + go(n - 3, e - 3, h - 4, a, b, c));
    return ans;
}

void solve(){
    long long int n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    // n --> no. of friends;
    // e --> no. of eggs available
    // h --> no. of chocolate bars available
    // a, b, c --> cost(omelette), cost(milkshake), cost(cake) respectively
    // 2 eggs for omelette, 3 chocolate bars for milkshake, 1 egg and 1 bar for cake;
    long long ans = go(n, e, h, a, b, c);
    cout << (ans >= 1e12 ? -1 : ans) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
