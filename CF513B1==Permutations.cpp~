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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
vll v;
int n;
ll f(){
	ll sum = 0;
	fr(i,0,n){

		fr(j,i,n){
			ll menor = linf;
			fe(l, i, j){
				menor = min(menor, v[l]);
			}	
			sum +=menor;
		}

	}
	return sum;
}


vector< pair<ll, vll> > vres;

bool cmp(pair<ll, vll> a, pair<ll, vll> b){
	return a.st > b.st; 
	if( a.st > b.st ) return 1;
	else if (b.st > a.st) return 0;
	fr(i,0,a.nd.size()){
		if( a.nd[i] < b.nd[i] ) return 1;
		if( a.nd[i] > b.nd[i] ) return 0;		
	}
	return 0;
	
	
}

int main (int argc, char const* argv[]){
	int m;
	sc2(n,m);
	fr(i,0,n) v.pb(i+1);

	ll sum;
	vll v2;
	do{
		sum = f();
		//printf("sum: %I64d\n", sum);
		
		v2 = v;
		//printf("oi\n");
		vres.pb(mp(sum, v2));
	
	}while(next_permutation(v.begin(), v.end()));
	stable_sort(vres.begin(), vres.end(), cmp);
	if(0) fr(i,0,vres.size()){
		printf("w: %I64d \n", vres[i].st );
		//pv(vres[i].nd, x);
	
	}
	
	v2.clear();
	v2 = vres[m-1].nd;
	fr(i,0,v2.size()){
		printf("%I64d", v2[i]);
		if(i!=v2.size()-1) printf(" ");
	}
	
	_
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
