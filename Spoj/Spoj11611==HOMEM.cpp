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
	int maos[5];
	Node(){maos[0]=maos[1]=maos[2]=0;}
	Node(int _h, int _e, int _r){ maos[0]=_h, maos[1]=_e, maos[2]=_r;}
	int& operator [](int i){ return maos[i]; }
	void gire(int k){
		int of;
		int arr2[3]; fr(i,0,3) arr2[i] = maos[i];
		fr(i,0,3){
			of = (i-k)%3; if(of<0) of+=3;
			maos[i] = arr2[ of];
		}
	}
	Node operator + (Node no){
		fr(i,0,3) no[i]+=maos[i];
		return no;
	}
	void pf(){fr(i,0,3) printf("%d ", maos[i]); _}
};
int arr[100005];
Node tree[4*100005];
int lazy[4*100005];

void atualize(int no){
	fr(i,0,3){
		tree[no][i] = tree[2*no][i] + tree[2*no+1][i];
	}
//	tree[no].h = tree[2*no].h + tree[2*no+1].h;
//	tree[no].e = tree[2*no].e + tree[2*no+1].e;
//	tree[no].r = tree[2*no].r + tree[2*no+1].r;		
}

void build(int no, int a, int b){
	if(a > b ) return;
	if(a==b) {tree[no] = Node(1, 0, 0); return;}
	build(2*no, a, (a+b)/2 );
	build(2*no +1, ((a+b)/2)+1, b );
	atualize(no);
}

void update(int no, int a, int b, int i, int j, int val){
		if(lazy[no]){
			//tree[no] += lazy[no];
			tree[no].gire(lazy[no]);
			if(a!=b){
				lazy[2*no] += lazy[no];
				lazy[2*no +1] += lazy[no];
			}
			lazy[no] = 0;
		}
		if(a >b || b < i || a > j ) return;
		
		if(i <= a && b <= j){
			//tree[no] += val;
		//	printf("Entrou [%d, %d] | girar %d\n", a, b, val);
		//	printf("antes e depois:\n");
		//	tree[no].pf();
			tree[no].gire(val);
		//	tree[no].pf();
			if(a!=b){
				lazy[2*no] += val;
				lazy[2*no +1] += val;
			}
			return;
		}
		update(2*no, a ,  (a+b)/2, i, j, val );
		update(2*no + 1, ((a+b)/2)+1, b, i, j, val );
		atualize(no);
}	


Node query(int no, int a, int b, int i, int j){
	if(lazy[no]){
		//tree[no] += lazy[no];
		tree[no].gire(lazy[no]);
		if(a!=b){
			lazy[2*no] += lazy[no];
			lazy[2*no + 1] += lazy[no];
		}
		lazy[no]=0;
	}
	if(a > b ||  a > j || b < i ) return Node();
	if(i <= a && b <= j ){
		return tree[no];
	}
	Node q1,q2;
	q1 = query(2*no, a ,  (a+b)/2, i, j );
	q2 = query(2*no + 1, ((a+b)/2)+1, b, i, j);
	return q1+q2;
}




char str[5]; 
int main (int argc, char *argv[]) {
	int M,N, a, b;
	Node res;
	while( sc2(N,M) ==2 ) {
		fe(i,1,4*N+20) lazy[i]=0;
		fe(i,1,N) arr[i] = 1;
		build(1, 1, N);
		fr(i,0,M){
			scanf("%s %d %d", str, &a, &b);
			if(str[0]=='C'){
				res = query(1, 1,N, a,b);
				printf("%d %d %d\n", res[0], res[1], res[2] );
			}
			else{
			//	printf("UPDATE\n");
				update(1, 1,N, a, b, 1);
			}
		}
		_
	}

	
	return 0;
}




