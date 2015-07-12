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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

inline int mod(int k){
	return ((k % 8) + 8) % 8;
}

int pot[4] = {  1 % 8,  10 % 8, 100 % 8 };

struct boy
{
	int p, k, cnt, leading;
	int w;
	boy(){}
	boy(int _p, int _k, int _cnt, int _leading, int _w){
		p=_p, k=_k, cnt=_cnt, leading=_leading;
		w=_w;
		
	}
	/* data */
};

int pd[105][30][5][2];
boy pai[105][30][5][2];

int L;
string str;
bool go(int p, int k, int cnt, bool leading){
//	printf("%d %d %d\n", p, k, cnt);
	if( k == 0 && cnt >= 1 && leading){  
		//printf(" a a   a entrou\n");
		return 1;
	}
	if( p >= L || cnt >= 3 ) return 0;
	if(pd[p][k][cnt][leading] != -1) return pd[p][k][cnt][leading];
	
	int r  = 0;
	int w = str[p] - '0';  
	if( go(p+1, mod(k + w*pot[cnt]) , cnt+1, leading | (cnt==0 && w != 0 ) ) ){
		pai[p][k][cnt][leading] = boy(p+1,  mod(k + w*pot[cnt]), cnt+1, leading | (cnt==0 && w != 0 ), w );
		r = 1;
	}
	if(!r){
		r = go(p+1, k, cnt, leading);
		pai[p][k][cnt][leading] = boy(p+1, k, cnt, leading, -1 );
	}
	
	
	//return r;
	return pd[p][k][cnt][leading] = r;
}



vi v;
void getPath(int p, int k, int cnt, bool leading){
	if(p==-1) return;
	int w = pai[p][k][cnt][leading].w;
	if(w != -1) v.pb(w); 
	getPath(pai[p][k][cnt][leading].p, pai[p][k][cnt][leading].k, pai[p][k][cnt][leading].cnt, pai[p][k][cnt][leading].leading);
}



int main (int argc, char const* argv[]){
	//[105][30][5][2];
	fr(i,0,105) fr(j,0,30) fr(k,0,5) fr(l,0,2){
		pai[i][j][k][l] = boy(-1,-1,-1,-1, -1);
	}
	mst(pd, -1);
	getline(cin, str);
	reverse(str.begin(), str.end());
	L = str.length();
	int r= go(0, 0, 0, 0);

//	printf("R: %d\n", r);
	if(r){	
	printf("YES\n");
	getPath(0, 0, 0, 0);
	reverse(v.begin(), v.end());
		printf("%d", v[0]);
		fr(i,1,v.size())printf("%d", v[i]);
		_
	}
	else {
		bool ok =0 ;
		fr(i,0,L) if(str[i] == '0') {
			ok = 1;
			break;
		}
		if(!ok) printf("NO\n");
		else printf("YES\n0\n");
	
	}
	
	return 0;
}
