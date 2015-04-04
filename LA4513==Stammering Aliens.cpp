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
#define pvl(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;





string str;
int len, M;
ll base = 29;


ll fexp(ll a, ll b) {
	if(!b) return 1;
	ll r=1;
	for(ll k = 1; k <= b ;k<<=ll(1), a*=a){
		if( b & k ) r *= a;
	}
	return r;
}
typedef pair<ll, bool> llb; 
bool mycmp(pair<ll, int> a , pair<ll, int> b ) {
	return a.st == b.st ? a.nd < b.nd : a.st < b.st;
}

pair<bool, int>  f(int m){
	if( m>len ) return mp(0,0);
	vector<pair<ll,int> >  v;
	int i=0, j=0; ll sum =0;
	for(;j<m; j++ ){
		sum = base*sum + str[j]-'a'+1;
	}
	
	v.pb(mp(sum,0) );
	while( j < len ) {
		ll h = (str[i]-'a'+1)*fexp(base, m-1);
		sum -= h; sum*=base; sum+=str[j]-'a'+1;
//		printf("h: %lld\n", h);
		j++; i++;
		v.pb(mp(sum,i) );		

	}
	sort(v.begin(), v.end(),mycmp);
//	pvl(v,x);
	int k = !v.empty();
	int p = 0;
	bool ok = k >= M;
	fr(i,1,v.size()){
		if(v[i-1].st == v[i].st) k++;
		else {
			k=1;
		}
		if(k>=M) {
			p = max(p, v[i].nd);
			ok = 1; 
		}
	} 
	return mp(ok,p);
}
ii mymax(ii a, ii b) {
	return a.st == b.st ? ((a.nd > b.nd) ?a:b) : (a.st > b.st ?a:b) ;
}	

ii bs(int lo, int hi){
	if(lo+1 >= hi) return mp(-inf, -inf);
	pair<bool, int> r;	
	int mid = (lo+hi)/2;
	r = f(mid);
	if(r.st) return mymax( mp(mid, r.nd) , bs(mid, hi));
	return bs(lo, mid);
}



int main (int argc, char const* argv[]){
	ii r;
	while(1){
		sc1(M); iz(M);
		getline(cin,str);
		getline(cin,str);
		len = str.length();
//		printf("f: %d\n", f(2));	
//		break;
		r = bs(0, len+1);

		if(r.st <= -inf)  printf("none\n");
		else {
			printf("%d %d\n", r.st, r.nd);
//			int i = 0, j =0;
			
		}
	
	}
	
	
	
	return 0;
}








