#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {

    int z;
    cin >> z;
    while (z--) {
        ll n;
        cin >> n;

        ll ans = n * (n + 1) / 2;

        ll cnt = 0, maxi = 0;

        for (ll i = 0; i < n; i++) {
            ll t;
            cin >> t;
            if (t & 1) {
                cnt++;
            } else {
                ans -= (cnt + 1) * (cnt) / 2;
                maxi = max(maxi, cnt);
                cnt = 0;
            }
        }
        maxi = max(maxi, cnt);

        ans -= cnt * (cnt + 1) / 2;

        if (maxi == 0) {
            cout << ans << '\n';
            return 0 ;
        }
        ans += maxi * (maxi + 1) / 2;

        if (maxi & 1) {
            maxi >>= 1;
            ans -= (maxi + 1) * maxi;
        } else {
            maxi >>= 1;
            ans -= maxi * (maxi + 1) / 2;
            maxi--;
            ans -= maxi * (maxi + 1) / 2;
        }


        cout << ans << '\n';
    }


    return 0;
}