#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;
long long n, x, y;
long long dp[N];

long long go(int i){
    if(i == 1) return x;
    if(i <= 0) return 0;
    if(dp[i] != -1)
        return dp[i];
    long long a, b;
    if(i % 2 == 0){
        b = min(x * (i/2), y) + go(i/2);
        a = b; 
    }
    else{
        a = x + go(i - 1);
        b = y + x + go((i + 1) / 2);
    }
    return dp[i] = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof dp);
    cin >> n >> x >> y;
    cout << go(n) << '\n';
}