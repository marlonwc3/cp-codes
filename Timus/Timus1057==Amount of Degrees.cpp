#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define oi(x) cout << "Oi[" << x << "]" << endl
#define nd second
#define EPS 1e-8
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;


ll qnt(ll n){
	ll r = 0 ;
	while(n){ r+=n%2; n/=2; }
	return r;
}

ll B, K;
ll nDig;
ll last(ll n){
	ll r = -1;
	for(ll i = 0; i <= nDig; i++){
		assert(( 1LL<<i) > 0 );
		if(n & ( 1LL<< i) ) r = i;
	}
	return r;
}

ll cmb[40][40];




ll f(ll n){
	nDig = (log(n)/log(B))+1;
	ll k = K;
	ll ans = 0;
	ll p = last(n);
	if(p!=-1){
		for(ll i = p; i >= 0 && i >= k && k >= 0 ; i--){
			if(n & (1LL<<i)){
				assert(k>=0);
				assert(cmb[i][k] >= 0);
				ans += cmb[i][k];
				k--;
			} 
		}
	}
	ans += qnt(n) == K;
	return ans;

}
ll get(ll a, ll b){
	ll r = f(b) - ((a==1) ? 0 :  f(a-1));
	assert(r >= 0 );
	return r;
}

ll pot[40];


				vi v;
int main (int argc, char const* argv[]){
	
	//3⁹+3⁸+3⁷+3⁶+3⁵+3⁴+3³+3²+3¹+3⁰
	/*
	ll w = 0;
	fe(i,0,8){
		w += pow(3,i);
	}

	printf("w: %lld\n", w);
	*/
	fe(i,0,35) cmb[i][0] = 1;
	fe(i,1,35){
		fe(j,1,i) cmb[i][j] = cmb[i-1][j] + cmb[i-1][j-1];
	}
	if(0) {
		fe(i,0,10){
			printf("i: %d |", i);
			fe(j,0,i+1) printf(" %lld", cmb[i][j]);
			_
		}
	}
	ll X, Y;
	
	while( scanf("%lld %lld %lld %lld", &X, &Y, &K, &B) == 4 ) {
	//	_
	//	printf("X: %lld | Y: %lld | K: %lld | B: %lld\n", X,Y,K,B);

		if(B == 2 ) {
			printf("%lld\n", get(X, Y));
		}
		else {
			ll ans = 0;
			nDig = (log(Y)/log(B))+1;
			//fe(i,0,Y) to(i, 1, K);	
			//printf("nDig: %lld\n", nDig);
			if(K > nDig) { printf("0\n");  }
			else{
				v.clear();
			//	oi(K);
				pot[0] = 1;
				fe(i,1,nDig) pot[i] = B*pot[i-1];		
				
				if(0){
					fe(i,0,nDig){
						printf("%lld ", pot[i]);
					}
					_
				}

				fr(i,0,K) v.pb(1);
//				printf("size: %d\n", int(v.size() ) );
				fr(i,0,nDig-K) v.pb(0);
				
				sort(v.begin(), v.end());
				//pv(v,x);
				do{
					
	//			    pv(v,x);
					ll sum = 0;
					fr(i,0,v.size() ){
//						printf("pot i: %lld \n", pot[i]);
						if(v[i]){
							sum += pot[i];
						}
					}
				//	printf("sum: %lld\n", sum);
					if(sum >= X && sum <= Y)  ans++;
			
			
		
				}while(next_permutation(v.begin(), v.end()));
				printf("%lld\n", ans);
		
			}	
		
		}
	}
	
	
	return 0;
}



















