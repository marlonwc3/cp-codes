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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
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

#define LSOne(S) (S & (-S) )
vll t;
void ft_create(int n) {t.assign(n+1, 0); } 
ll ft_rsq(int b){
	ll sum = 0;
	for(; b; b-=LSOne(b)) sum += t[b];
	return sum;
}

ll ft_rsq(int a, int b ) { 
	return ft_rsq(b) - ((a==1) ? 0 : ft_rsq(a-1)); 
}
void ft_adjust(int k, ll v) {
	for(;k <= (int)t.size(); k+=LSOne(k) ) t[k]+=v;
}




char line[100];

int main (int argc, char const* argv[]){
	int n,k;
	
	char ch;	
	ll w, a, b, r;
	while(sc2(n,k)==2) {
		ft_create(n+2);
		fe(i,1,n){
			scanf("%lld", &w);
			//printf("w: %lld\n", w);
			if(w==0){
				ft_adjust(i, -inf);
				//printf("zero em %d\n", i);
			}
			else if( w < 0 ) {
				//printf("botando 1 em %d\n", i);
				ft_adjust(i, 1);
				//printf("rsq: %lld\n", ft_rsq(i));
			}
			else {
				ft_adjust(i, 0);
			}
		}
	//	r = ft_rsq(1, 4);
	//	printf("1 -> 2  : %d \n", r);
	//	printf("OI\n");
		gets(line);
		ll antes;
		fr(i,0,k){
			gets(line);
			sscanf(line, "%c %lld %lld", &ch, &a, &b);
		//	printf("ch: %c | a: %d | b: %d\n", ch, a, b);
			if(ch=='C'){
				antes =ft_rsq(a,a);
				ft_adjust(a, -antes);
				if(b==0){
					ft_adjust(a, -inf);
				}
				else if( b < 0 ) {
					ft_adjust(a, 1);
				}
				else {
					//printf("botou a:%d | 0!\n", a);
					ft_adjust(a, 0);
				}
			}
			else{
	

			    r = ft_rsq(a,b);
			//printf("rsq %d %d -> %d\n", a, b, r);
			
				if(r < 0 ) printf("0");
				else if(r%2 == 0 ) printf("+");
				else printf("-");
			}
		}
		_
		
		
	
	
	}
	
	
	
	
	
	
	return 0;
}







