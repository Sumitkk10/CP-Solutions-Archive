#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), prefix(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            prefix[i] = 1;
        }
        for(int i = n - 2; i >= 0; --i){
            if(a[i] < 0){
                if(a[i+1] > 0)
                    prefix[i] = prefix[i+1] + 1;
                else
                    prefix[i] += 0;
            }
            else{
                if(a[i+1] < 0)
                    prefix[i] = prefix[i+1] + 1;
                else
                    prefix[i] += 0;
            }
        }
        for(int i = 0; i < n; ++i)
            cout << prefix[i] << ' ';
        cout << endl;
    }
    return 0;
}