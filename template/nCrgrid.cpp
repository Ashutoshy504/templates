#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define f first
#define N 200005
#define mod 998244353
#define s second
ll fact[N];
ll ifact[N];
ll power(ll a , ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans *= ((a)%mod); ans = ans%mod;
        }
        b =b >>1;
        a = (a*a)%mod;
    }
    return ans%mod;
}
void pre(){
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1 ; i< N ; i++){
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = power(fact[i],mod-2);
    }
}
ll nCr(ll n , ll r){
    if(r == 0 || r == n) return 1;
    return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
int main() {
	fast  pre();
	int t;
	cin >> t;
//	cout<<ifact[2];
	while(t--){ ll  n , m , x1,y1,x2,y2;
	    cin >> n >> m >> x1 >> y1>>x2>>y2;
	   ll ans = nCr(n + m,n);
	//cout << ans << " ";
	ll ansX = (nCr(x1 + y1,x1) * nCr(n + m - x1 - y1,n - x1))%mod;
	ll ansY = (nCr(x2 + y2,x2) * nCr(n + m - x2 - y2,n - x2))%mod;
	ll ansXY = (((nCr(x1 + y1,x1) * nCr(x2 + y2 - x1 - y1,x2 - x1))%mod) * nCr(n + m - x2 - y2,n - x2))%mod;
	ans -= (ansX + ansY - ansXY);
	//cout << ansX << " " << ansY << " " << ansXY << "\n";
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << "\n";
	}
	return 0;
}
