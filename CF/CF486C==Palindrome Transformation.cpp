#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

char str[100005];
int dist(int i, int j){
	int ka = min ( str[i]-'a', str[j]-'a' ) ;
	int kb = max ( str[i]-'a', str[j]-'a' );	
	return min ( fabs(kb-ka), fabs( (kb-26) - ka  )      );
}

int main (int argc, char const* argv[]) {
	int n, p;
	sc2(n,p);
	p--;
	scanf("%s", str);
	int i =0, j = n-1, cont=0, te=0, td=0;
	int obe, obd;
	obe = obd = -1;
	int d;
	while( i < j ) {
		d = dist(i,j);
		if(!d) goto fim;
		cont+=d;
		if(i==p || j==p) { goto fim; }	
		if(  i < p && j < p ) {
			d = p-j;
			obe = max(d, obe);
		}
		else if( i> p && j > p ){
			d = i-p;
			obd = max(obd, d);
		}
		else {
			d = p-i;
			te = max(te, d);			
			d = j-p;
			td = max(td, d);
		}
		fim:;
		i++; j--;
	}
	int res;
	if( obd == -1 ) obd = inf;
	if ( obe == -1 ) obe = inf;
	if ( te ==0  && obe < inf   ) te = obe;
	if ( td ==0 && obd < inf ) td = obd;
	if (te == 0 && obe == 0)  {
		res = max(obd, td);
	} 
	else if (td == 0 && obd == 0){
		res = max(obe, te);
	}
	else {
		int op1 =  2*te + obd;
		int op2 = 2*td + obe;
		res = min(op1, op2);
		if( obe >= inf)  res = min(res, td );
		else {  
			int op3 = 2*obe + td;
			res = min(res, op3);
		}
		if ( obd >= inf ) res = min ( res, te );
		else{
			int op4 = 2*obd + te;
			res = min(res, op4);
		}
	}
	cont+=res;
	printf("%d\n", cont);
		
	return 0;
}








