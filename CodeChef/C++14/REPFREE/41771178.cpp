#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool ok(long long int x){
    string s = to_string(x);
    map<char, int> mp;
    for(auto k : s) {
        if (k == '0')
            return false;
        mp[k]++;
    }
    for(auto k : mp)
        if(k.second > 1)
            return false;
    return true;
}

int main(){
    fast;
    long long int n;
    cin >> n;
    if(n >= 987654321) cout << "0\n";
    else{
        ++n;
        while(!ok(n) and n <= 987654321)
            ++n;
        if(n > 987654321) cout << "0\n";
        else cout << n << '\n';
    }
    return 0;
}