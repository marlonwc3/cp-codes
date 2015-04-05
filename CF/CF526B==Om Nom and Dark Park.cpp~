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

struct Node{
	int left, right, k;
	vi v;
	Node(){left=right=-1; k=0;v= vi();}
	Node(int _l, int _r, int _k ) {
		left=_l, right=_r, k=_k;
		 v = vi();
	}
};

#define MAX_N (1<<12)
Node tree[MAX_N+5];

int limit;
	int n;
int insert(int p){
	if( p < 0 || p > limit ) return -1;	
	//printf("p: %d\n", p);
	tree[p] = Node();
	tree[p].left  = insert(2*p);
	tree[p].right  = insert((2*p) + 1);	
	return p;
}

vi merge(vi v1, vi v2 ){
	vi r;
	fr(i,0,v1.size()) r.pb(v1[i]);
	fr(i,0,v2.size()) r.pb(v2[i]);	
	return r;
}


vi go(int p, int cnt){
//	printf("p: %d | cnt: %d\n", p, cnt);
	if( p < 0 || p > limit ) {
		vi v; v.clear();
		v.pb(cnt);
	//	printf("Folha !\n");
		return v;
	}
	vi v1 = go(tree[p].left, cnt+tree[p].k);
	vi v2 = go(tree[p].right, cnt+tree[p].k);
	if(tree[p].left == -1 && tree[p].right == -1 ) {
		tree[p].v = v1.empty()  ? v2 : v1;
	}
	else tree[p].v = merge(v1,v2);
	return tree[p].v;
}


int res;
int boy;
void vai(int p, int add) {
	
	if( p < 0 || p > limit ) return;
	int d;
	if(tree[p].left == -1 && tree[p].right == -1 ) {
		d= (boy - (tree[p].v[0] + add) );
		if(d > 0 ){
			res += d;
		}
		return;
		
	}
	else{
		bool p1 = 1, p2 = 1;
		int d1 = inf, d2 = inf;
		//printf("p:  %d\n de 0 ate %d\n", p, tree[p].v.size()/2);
		fr(i,0,tree[p].v.size()/2 ) {
		
			if( boy - (tree[p].v[i] + add ) <= 0  ){ p1=0; continue;}
			int x =  boy - (tree[p].v[i] + add) ;
			//printf("x :%d | tree[p].v[i] : %d \n", x, tree[p].v[i]);
			d1= min(d1,x);
		}
	//	printf("de : %d - -> %d\n", tree[p].v.size()/2,tree[p].v.size() );
		fr(i,tree[p].v.size()/2,tree[p].v.size() ) {
			if( boy - (tree[p].v[i] + add ) <= 0  ){p2=0; continue; }
			int x =  boy - (tree[p].v[i] + add) ;
			//printf("x :%d | tree[p].v[i] : %d \n", x, tree[p].v[i]);		
			d2= min(d2,x);
		}		
		//printf("p: %d | d1: %d | d2 : %d\n", p, d1, d2);
		int k = inf;
		if( d1 >= inf && d2 >= inf ) return;
		if( d1 < inf && d1 > 0 ) {
			if(p1){
				res+=d1;
				vai(tree[p].left,  add + d1);
			}
			else{
				vai(tree[p].left,  add);
			}
		}	
		if( d2 < inf && d2 > 0 ) {
			if(p2){
				res+=d2;
				vai(tree[p].right,  add + d2);
			}
			else{
				vai(tree[p].right, add);	
			}
		}		

		return;
	
	}
	

}



int main (int argc, char const* argv[]){
	res =0;
	sc1(n);
	limit = ((1<<(n+1)) -1);
//	printf("limit :%d \n", limit);
	tree[1] = Node();
	tree[1].left = insert(2);
	tree[1].right = insert(3);	
	int k;
	fe(i,2,limit){
		sc1(k);
		tree[i].k = k;
	}
	vi r = go(1, 0);
	//pv(r,x);
	boy = 0; fr(i,0,r.size() ) { boy = max(boy, r[i]); }
	vai(1, 0);
	//printf("Boy: %d\n", boy);
	printf("%d\n", res);
	
		
	return 0;
}
