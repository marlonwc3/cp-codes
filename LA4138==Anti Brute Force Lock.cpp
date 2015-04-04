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

int get(string a, string b){
	int r = 0;
	int ka, kb;
	fr(i,0,4){
		ka = a[i]-'0'; kb = b[i]-'0';
		int lol = min( abs(kb - ka), abs( ka - kb) );
		lol = min(lol, abs(kb+10 -ka) ); lol = min(lol, abs(ka+10 - kb) );  
	//	printf("%c -> %c == %d\n", a[i], b[i], lol	);
		r += lol;
	}
	return r;
}

int rep[515];
void init(int n){fe(i,0,n+1) rep[i]=i; }
int find(int a){return (rep[a]==a) ? a : rep[a] = find(rep[a]); }
bool iss(int a,int b) {return find(a)==find(b);}
void uni(int a,int b){ rep[find(a)]=find(b); }

struct edge {
	int a, b, w;
	edge(){}
	edge(int _a, int _b, int _w){ a=_a,b=_b,w=_w;}
	bool operator < (const edge &e)const{ return w < e.w;}
};

edge arr[505*505];
int NEXT;
vector<string> v;

int go(){
	edge e;
	int a, b, w, sum = 0;
	fr(i,0,NEXT ){
		a = arr[i].a, b=arr[i].b, w = arr[i].w;
		if(iss(a,b))continue;
		uni(a,b);
		sum+=w;
	}
	return sum;
}
char str[5];

int main (int argc, char const* argv[]) {
	int t, n, k;
	sc1(t);
	while(t--){
		v.clear();
//		arr.clear();
		NEXT=0;
		sc1(n);
		init(n+1);
//		printf("%s\n", v[0]);
		int r1=inf;
		fr(i,0,n){
			scanf("%s", str);
			v.pb(str);
			r1 = min(r1, get("0000", str));
			fr(j,0,i){
				k = get(v[i], v[j]);
				//arr.pb( edge(i , j, k) );
				arr[NEXT++] =edge(i,j,k);
			}
		}
		sort(arr, arr+NEXT);
		sort(v.begin(), v.end() );
		int lol=0, lol2=0; 
		k = go();
		printf("%d\n", k+r1);
	}
	return 0;
}





















