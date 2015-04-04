#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
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

vector<ll> v1, v2;
bool last; // 1 == v1, 2 == v2

int main (int argc, char const* argv[]) {
	char r1[10] = "first", r2[10] = "second";
	

	int n, k;	
	ll s1, s2;
	s1=s2=0;
	sc1(n);
	last = 1;
	while(n--){
		sc1(k);
		if(k>0) {
			v1.pb(k);
			last = 0;
			s1 += k;
		}
		else {
			k*=-1;
			s2 += k;
			v2.pb( k );
			last = 1;
		}
	}
	if(s1>s2) {
		printf("%s\n", r1);
	}
	else if(s2>s1){
		printf("%s\n", r2);
	}
	else {
		int res = 0;
		int s = min( v1.size(), v2.size() );	
		fr(i,0,s){
			if(v1[i] > v2[i]) {res = 1; break;}
			else if (v2[i] > v1[i]) {res =2 ; break;}
		}
		

		
		if(res == 1) {
			printf("%s\n", r1);
		}
		else if (res==2){
			printf("%s\n", r2);
		}
		else {
			if( v1.size() > v2.size()   ) {
				printf("%s\n", r1);						
			}
			else if(v2.size() > v1.size()  ) {
				printf("%s\n", r2);						
			}
			else {
				if ( !last ) {
					printf("%s\n", r1);
				}
				else {
					printf("%s\n", r2);	
				}
			}
		
		}
	
	}
	
	
	
	return 0;
}

