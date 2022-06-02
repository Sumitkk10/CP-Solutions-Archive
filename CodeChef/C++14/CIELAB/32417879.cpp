#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = a-b;
    if(ans%10 == 9)
        ans = ans-1;
    else
        ans = ans+1;
    cout << ans;
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!