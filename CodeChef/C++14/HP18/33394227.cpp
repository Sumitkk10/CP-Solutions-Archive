#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        ll arr[n], cnt = 0, cnt1 = 0, x = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] % a == 0 && arr[i] % b == 0)
                ++x;
            else if(arr[i] % a == 0)
                ++cnt;
            else if(arr[i] % b == 0)
                ++cnt1;
        }
        if(a == b)
            cout << "BOB" << '\n';
        else{
            if(x > 0)
                --cnt1;
            if(cnt > cnt1)
                cout << "BOB\n";
            else if(cnt <= cnt1)
                cout << "ALICE\n";
        }
    }
    return 0;
}
