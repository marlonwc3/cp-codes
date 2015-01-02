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
#define pv(a, i) for(int (i) =0 ; (i) < ( (a).size()+0 ); (i)++ ) {printf("%d ",a[(i)]); if((i)==a.size() - 1 )_  }
#define pvp(a, i) for(int (i) =0 ; (i) <( (a).size()+0 ); (i)++ ) {printf("%d %d ~ ",a[(i)].st, a[(i)].nd); if((i)==(a).size() - 1 )_  }
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


vii v;
int main (int argc, char const* argv[]) {
	ll n, r, avg, k, total=0, sum=0, a, b; 
	scanf("%I64d %I64d %I64d", &n , &r , &avg);
	fr(i,0,n){
        scanf("%I64d %I64d", &a, &b);
		sum+=a;
		v.pb(mp(b,a));
	}
	total = n*avg;
	if(sum >= total){
	    printf("0\n");
	    return 0;
	}
	total-= sum;
	

	
	if(total<0){
	    printf("n: %I64d | avg: %I64d | sum: %I64d\n", n, avg, sum);
	}
	sort(v.begin(), v.end());
    ll pt, cnt = 0;
	fr(i,0,n){
		b = v[i].st;
		a = v[i].nd;
		pt = r-a;
		if(pt<=0) continue;
		if(pt <= total ){
			total-=pt;
			cnt += pt*b;
		}
		else {	
			cnt += total*b;
			if(cnt < 0 ){
			    printf("a-> %I64d | b-> %I64d | total: %I64d | pt: %I64d | r: %I64d | mult: %I64d\n", a, b, total, pt, r, total*b);
			}
			
			total = 0;				
		}
		if(total<=0) break;
	}
	if(cnt<0) cnt = 0;
	printf("%I64d\n", cnt);
	
	return 0;
}
