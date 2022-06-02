#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int a[4];
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    sort(a, a + 4);
    cout << a[0] * a[2] << '\n'; 
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}