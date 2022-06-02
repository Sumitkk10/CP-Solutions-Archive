#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;
int dp[N][N];
string s;
int is_palindrome[N][N];

int go(int l, int r){
    if(l == r - 1){
        if(s[l] == s[r])
            return 3;
        else
            return 2;
    }
    if(l == r)
        return 1;
    if(r < l)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = (go(l, r - 1) + go(l + 1, r) - go(l + 1, r - 1) + is_palindrome[l][r]);
}

bool solve(int i, int j){
    if(j < i)
        return false;
    if(i == j)
        return true;
    if(i == j - 1){
        if(s[i] == s[j])
            return true;
        else
            return false;
    }
    if(is_palindrome[i][j] != -1)
        return is_palindrome[i][j];
    if(s[i] != s[j])
        return is_palindrome[i][j] = false;
    return is_palindrome[i][j] = solve(i + 1, j - 1);
}

int main(){
    fast;
    cin >> s;
    memset(dp, -1, sizeof dp);
    memset(is_palindrome, -1, sizeof is_palindrome);
    for(int i = 0; i < s.size(); ++i)
        is_palindrome[i][i] = true;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == s[i + 1])
            is_palindrome[i][i + 1] = true;
        else
            is_palindrome[i][i + 1] = false;
    for(int i = 0; i < s.size(); ++i)
        for(int j = i + 2; j < s.size(); ++j)
            if(is_palindrome[i][j] == -1)
                solve(i, j);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << go(l, r) << "\n";
    }
    return 0;
}
