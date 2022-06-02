#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); i += 2){
        if(a[i] == 'a')
            a[i] = 'b';
        else
            a[i] = 'a';
    }
    for(int i = 1; i < a.size(); i += 2){
        if(a[i] == 'z')
            a[i] = 'y';
        else
            a[i] = 'z';
    }
    cout << a << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}