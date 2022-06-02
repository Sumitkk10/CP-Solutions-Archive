#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, p, x;
        cin >> n >> p;
        ll a[n+1][n+1];
        if(n <= 2){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j < n; ++j){
                    cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                    cin >> x;
                    if(x == 2){
                        a[i][j] = 1;
                        a[i][j+1] = 1;
                        ++j;
                    }
                    else if(x == 0){
                        a[i][j] = 0;
                        a[i][j+1] = 0;
                        ++j;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j << endl;
                        cin >> x;
                        a[i][j] = x;
                        if(x == 0)
                            a[i][j+1] = 1;
                        else
                            a[i][j+1] = 0;
                        ++j;
                    }
                }
                if(n%2 != 0){
                    ll y;
                    cout << 1 << ' ' << i << ' ' << n << endl;
                    cin >> y;
                    a[i][n] = y;
                }
            }
            cout << 2 << endl;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    cout << a[i][j] << ' ';
                }
            cout << endl;
            }
            ll e;
            cin >> e;
            if(e == -1)
                break;
        }
        else if(n == 3){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j < n-1; ++j){
                    cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+2 << endl;
                    int x;
                    cin >> x;
                    if(x == 3){
                        a[i][j] = 1;
                        a[i][j+1] = 1;
                        a[i][j+2] = 1;
                        j += 2;
                    }
                    else if(x == 0){
                        a[i][j] = 0;
                        a[i][j+1] = 0;
                        a[i][j+2] = 0;
                        j += 2;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                        cin >> x;
                        if(x == 0){
                            a[i][j+1] = 0;
                            a[i][j] = 0;
                            a[i][j+2] = 1;
                        }
                        else if(x == 1){
                            a[i][j+2] = 0;
                            cout << 1 << ' ' << i << ' '<< j << ' ' << i << ' ' << j << endl;
                            cin >> x;
                            a[i][j] = x;
                            if(x == 0)
                                a[i][j+1] = 1;
                            else
                                a[i][j+1] = 0;
                        }
                        j += 2;
                    }
                    else if(x == 2){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                        cin >> x;
                        if(x == 2){
                            a[i][j+1] = 1;
                            a[i][j] = 1;
                            a[i][j+2] = 0;
                        }
                        else if(x == 1){
                            a[i][j+2] = 1;
                            cout << 1 << ' ' << i << ' '<< j << ' ' << i << ' ' << j << endl;
                            cin >> x;
                            a[i][j] = x;
                            if(x == 0)
                                a[i][j+1] = 1;
                            else
                                a[i][j+1] = 0;
                        }
                        j += 2;
                    }
                }
                if(n % 3 == 1){
                    cout << 1 << ' ' << i << ' ' << n << ' ' << i << ' ' << n << endl;
                    cin >> x;
                    a[i][n] = x;
                }
                if(n % 3 == 2){
                    cout << 1 << ' ' << i << ' ' << n-1 << ' ' << i << ' ' << n << endl;
                    cin >> x;
                    if(x == 2){
                        a[i][n] = 1;
                        a[i][n-1] = 1;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << n-1 << ' ' << i << ' ' << n-1 << endl;
                        cin >> x;
                        a[i][n-1] = x;
                        if(x == 0)
                            a[i][n] = 1;
                        else
                            a[i][n] = 0;
                    }
                }
            }
            cout << 2 << endl;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
            ll e;
            cin >> e;
            if(e == -1)
                break;
        }  
        else{
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j < n-2; ++j){
                    cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+3 << endl;
                    int x;
                    cin >> x;
                    if(x == 4){
                        a[i][j] = 1;
                        a[i][j+1] = 1;
                        a[i][j+2] = 1;
                        a[i][j+3] = 1;
                        j += 3;
                    }
                    else if(x == 0){
                        a[i][j] = 0;
                        a[i][j+1] = 0;
                        a[i][j+2] = 0;
                        a[i][j+3] = 0;
                        j += 3;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                        cin >> x;
                        if(x == 0){
                            a[i][j+1] = 0;
                            a[i][j] = 0;
                            cout << 1 << ' ' << i << ' ' << j + 2 << ' ' << i << ' ' << j + 2 << endl;
                            cin >> x;
                            if(x == 0){
                                a[i][j+2] = 0;
                                a[i][j+3] = 1; 
                            }
                            else{
                                a[i][j+2] = 1;
                                a[i][j+3] = 0;
                            }
                        }
                        else if(x == 1){
                            a[i][j+2] = 0;
                            a[i][j+3] = 0;
                            cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j << endl;
                            cin >> x;
                            a[i][j] = x;
                            if(x == 0)
                                a[i][j+1] = 1;
                            else
                                a[i][j+1] = 0;
                        }
                        j += 3;
                    }
                    else if(x == 2){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                        cin >> x;
                        if(x == 2){
                            a[i][j+1] = 1;
                            a[i][j] = 1;
                            a[i][j+2] = 0;
                            a[i][j+3] = 0; 
                        }
                        else if(x == 0){
                            a[i][j] = 0;
                            a[i][j+1] = 0;
                            a[i][j+2] = 1;
                            a[i][j+3] = 1;
                        }
                        else if(x == 1){
                            cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j << endl;
                            cin >> x;
                            a[i][j] = x;
                            if(x == 0)
                                a[i][j+1] = 1;
                            else
                                a[i][j+1] = 0;
                            cout << 1 << ' ' << i << ' ' << j + 2 << ' ' << i << ' ' << j + 2 << endl;
                            cin >> x;
                            a[i][j+2] = x;
                            if(x == 0)
                                a[i][j+3] = 1;
                            else
                                a[i][j+3] = 0;
                        }
                        j += 3;
                    }
                    else if(x == 3){
                        cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+2 << endl;
                        cin >> x;
                        if(x == 3){
                            a[i][j] = 1;
                            a[i][j+1] = 1;
                            a[i][j+2] = 1;
                            a[i][j+3] = 0;
                        }
                        else if(x == 2){
                            a[i][j+3] = 1;
                            cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j << endl;
                            cin >> x;
                            if(x == 0){
                                a[i][j] = x;
                                a[i][j+1] = 1;
                                a[i][j+2] = 1;
                            } 
                            else{
                                a[i][j] = x;
                                cout << 1 << ' ' << i << ' ' << j + 1 << ' ' << i << ' ' << j + 1 << endl;
                                cin >> x;
                                a[i][j+1] = x;
                                if(x == 0)
                                    a[i][j+2] = 1;
                                else
                                    a[i][j+2] = 0;
                            }
                        }  
                        j += 3;
                    }
                }
                if(n % 4 == 1){
                    cout << 1 << ' ' << i << ' ' << n << ' ' << i << ' ' << n << endl;
                    cin >> x;
                    a[i][n] = x;
                }
                if(n % 4 == 2){
                    cout << 1 << ' ' << i << ' ' << n-1 << ' ' << i << ' ' << n << endl;
                    cin >> x;
                    if(x == 2){
                        a[i][n] = 1;
                        a[i][n-1] = 1;
                    }
                    else if(x == 0){
                        a[i][n] = 0;
                        a[i][n-1] = 0;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << n-1 << ' ' << i << ' ' << n-1 << endl;
                        cin >> x;
                        a[i][n-1] = x;
                        if(x == 0)
                            a[i][n] = 1;
                        else
                            a[i][n] = 0;
                    }
                }
                if(n % 4 == 3){
                    cout << 1 << ' ' << i << ' ' << n-2 << ' ' << i << ' ' << n << endl;
                    cin >> x;
                    if(x == 3){
                        a[i][n] = 1;
                        a[i][n-1] = 1;
                        a[i][n-2] = 1;
                    }
                    else if(x == 0){
                        a[i][n] = 0;
                        a[i][n-1] = 0;
                        a[i][n-2] = 0;
                    }
                    else if(x == 1){
                        cout << 1 << ' ' << i << ' ' << n-2 << ' ' << i << ' ' << n-1 << endl;
                        cin >> x;
                        if(x == 0){
                            a[i][n] = 1;
                            a[i][n-1] = 0;
                            a[i][n-2] = 0;
                        }
                        else if(x == 1){
                            a[i][n] = 0;
                            cout << 1 << ' ' << i << ' ' << n-2 << ' ' << i << ' ' << n - 2 << endl;
                            cin >> x;
                            a[i][n-2] = x;
                            if(x == 0)
                                a[i][n-1] = 1;
                            else
                                a[i][n-1] = 0; 
                        }
                    }
                    else if(x == 2){
                        cout << 1 << ' ' << i << ' ' << n-2 << ' ' << i << ' ' << n-1 << endl;
                        cin >> x;
                        if(x == 2){
                            a[i][n] = 0;
                            a[i][n-1] = 1;
                            a[i][n-2] = 1;
                        }
                        else if(x == 1){
                            cout << 1 << ' ' << i << ' ' << n-2 << ' ' << i << ' ' << n - 2 << endl;
                            cin >> x;
                            a[i][n-2] = x;
                            if(x == 0){
                                a[i][n-1] = 1;
                                a[i][n] = 1;
                            }
                            else{
                                cout << 1 << ' ' << i << ' ' << n - 1 << ' ' << i << ' ' << n - 1 << endl; 
                                cin >> x;
                                a[i][n-1] = x;
                                if(x == 0)
                                    a[i][n] = 1;
                                else
                                    a[i][n] = 0; 
                            }
                        }
                    }
                }
            }
            cout << 2 << endl;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
            ll e;
            cin >> e;
            if(e == -1)
                break;
        }
    }
    return 0;
}