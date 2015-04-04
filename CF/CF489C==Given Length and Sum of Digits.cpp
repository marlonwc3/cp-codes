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
typedef long double lb;


int n, s;
string a, b;
bool up(){
	int cnt = s;
	fr(i,0,n){
		if( cnt <= 9 ){
			a += cnt+'0';
			fr(j,i+1,n)  a+='0';
			
			cnt = 0; break;
		}
		else{
			a+='9';
			cnt -= 9;
		}
	}
	return cnt==0;
}

bool low(){
	int cnt = s-1;
	if( cnt < 0 && n!=1) return 0;
	fr(i,0,n-1){
		if ( cnt <= 9 ) {
			b = char(cnt + '0') + b ;
			cnt = 0;
			// add 0
			for(int j = i+1; j< n-1; j++){
				b = '0' + b;
			}
			b='1' + b; 
			return 1;
		}
		else {
			b = '9' + b;
			cnt -= 9;
		}
	}
//	printf("ter  %s\n", b.c_str() );
	if( cnt || n == 1 ) { 
		cnt++;
		//printf("pres %d\n", cnt);	
		
		if( cnt >= 0 && cnt <= 9 ) {
			b = char( cnt+'0' )  + b;
			return 1;
		}	
		else return 0;
	}
	return 1;
}


int main (int argc, char const* argv[]) {
	sc2(n,s);	
	bool ok1 = low();
	bool ok2 = up();
	//printf("ok l %d u %d\n", ok1, ok2	);
	if(!ok1 || !ok2){
		printf("-1 -1\n");
	}
	else printf("%s %s\n", b.c_str() , a.c_str());

	return 0;
}












