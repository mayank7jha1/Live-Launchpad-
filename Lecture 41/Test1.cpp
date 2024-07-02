#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define ff first
#define ss second
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define yes "Yes"
#define no "No"


signed main() {
  int n;
  cin >> n;
  vector<int>a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int total = (n * (n + 1)) / 2;
  int cnt = 0, cnt1 = 0;
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cnt1++;
      maxi = max(maxi, cnt1);
    }
    else {
      cnt += (cnt1 * (cnt1 + 1)) / 2;
      cnt1 = 0;
    }
  }
  int k = maxi / 2;
  int temp = 0;
  if (maxi % 2 == 0) {
    temp = (maxi * (maxi + 1)) / 2 - k * k;
  }
  else {
    temp = (maxi * (maxi + 1)) / 2 - k * k - k;
  }
  cnt += (cnt1 * (cnt1 + 1)) / 2;
  cout << total - cnt + temp << endl;
  return 0;
}