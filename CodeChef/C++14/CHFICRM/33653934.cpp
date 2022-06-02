#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007, N = 8001, M = 61;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        vector<ll> sum;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        if(a[0] != 5)
            cout << "NO\n";
        else{
            sum.push_back(5);
            ll no = 0, d = 0;
            for(int j = 1; j < n; ++j){
                if(a[j] == 5)
                    sum.push_back(a[j]);
                else{
                    ll k = a[j] - 5;
                    if(k == 5){
                        d = 0;
                        for(int i = 0; i < sum.size(); ++i){
                            if(sum[i] == 5){
                                ++d;
                                sum[i] = -1;
                                break;
                            }
                        }
                        if(d == 0){
                            ++no;
                            cout << "NO\n";
                            break;
                        }
                    }
                    else{
                        d = 0;
                        int e = 0;
                        for(int i = 0; i < sum.size(); ++i){
                            if(sum[i] == 10){
                                ++e;
                                sum[i] = -1;
                                break;
                            }
                        }
                        if(e == 0){
                            d = 0;
                            for(int i = 0; i < sum.size(); ++i){
                                if(sum[i] == 5)
                                    ++d;
                            }
                            if(d <= 1){
                                ++no;
                                cout << "NO\n";
                                break;
                            }
                            else{
                                for(int i = 0; i < sum.size(); ++i){
                                    if(sum[i] == 5){
                                        sum[i] = -1;
                                        break;
                                    }
                                }
                                for(int i = 0; i < sum.size(); ++i){
                                    if(sum[i] == 5){
                                        sum[i] = -1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    sum.push_back(a[j]);
                }
            }
            if(no == 0)
                cout << "YES\n";
        }
    }
    return 0;
}