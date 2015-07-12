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

const int LIMIT = 10000;
vi primes;
bool mark[LIMIT+10];
int pf[LIMIT+10];
void sieve(){
	mark[0] = mark[1] = pf[0] = pf[1] = 1;
	fe(i,2,LIMIT){
		if(mark[i]) continue;
		primes.pb(i);
		pf[i] = i;
		for(int j = ll(i) *i; j <= LIMIT; j+=i){
			mark[j] = 1;
			pf[j] = i;
		}
	}
}
map<int, int> mymap;
vii boys[LIMIT+10];
void f(int n){
	int aux = n;
	mymap.clear();
	while( n != 1) {
		//oi(n); oi(pf[n]);
		mymap[pf[n]]++;
		n/=pf[n];
	}
	//oi(3);
	for(map<int,int>::iterator it = mymap.begin(); it!=mymap.end(); it++){
		boys[aux].pb(*it);
	}
}

int cnt1[10005];
int cnt2[10005];

void add1(int n,int k=1){
	fe(j,2,n){
		fr(i,0,boys[j].size()) cnt1[boys[j][i].st] += k*boys[j][i].nd;
	}

}
void add2(int n){
	fr(i,0,boys[n].size()) cnt2[boys[n][i].st] += boys[n][i].nd;
}
int main (int argc, char const* argv[]){
	sieve();
	fe(i,2,LIMIT) f(i);
	int n,m, p,q, k;
	vector<double> v;
	while(sc4(n,m,p,q)==4){
		v.clear();
		mst(cnt1,0);
		mst(cnt2,0);		
	
		/*
			n! * q! * (p-q)!
		   -----------------
		    (n-m)!* m! * p!
		*/	
		add1(n); add1(q); add1(p-q);
		add1(n-m,-1); add1(m,-1); add1(p,-1);
		double res = 1;
		fr(i,0,primes.size()){
			k = primes[i];
			if(cnt1[k] == 0 ) continue;
			if(cnt1[k] > 0 ) {
				while(cnt1[k] > 0 ) {
					v.pb(k); cnt1[k]--;
				}
			}
			else if(cnt1[k] < 0 ) {
				while(cnt1[k] <0) {
					v.pb(1.0/k); cnt1[k]++;
				}
			}
		}
		if(0){
		fr(i,0,v.size()){
			printf("%.4lf ", v[i]);
		}
		_
		}
		int i  =0, j  = v.size()-1;
		while( i <= j  && i < v.size() ) {
			if(i == j ) res *= v[i];
			else res *= v[i]*v[j] ;
			i++; j--;
		}
		printf("%.5lf\n", res);
	}	
	
	
	
	return 0;
}



