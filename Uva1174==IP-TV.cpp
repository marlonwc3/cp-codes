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

int rep[2015];
int init (int n ){ fe(i,0,n+2) rep[i]=i;  }
int find(int a) { return rep[a] = ((rep[a]==a) ? a : find(rep[a]));  } 
int uni(int a, int b ) { rep[find(a)] = find(b);  }
bool iss(int a,int b) { return find(a)==find(b) ; }

struct edge{
	int a, b, w;
	edge(){}
	edge(int _a, int _b, int _w){ a=_a, b=_b, w=_w; }
	bool operator < (const edge &e ) const{
		return w < e.w;
	}
};
vector<edge> v;

int go(){
	int sum = 0;
	sort(v.begin(), v.end());
	int cnt = 0;
	int a,b,w;
	fr(i,0,v.size()){
		a= v[i].a, b=v[i].b, w = v[i].w;
		//printf("edge %d %d %d\n", a, b, w);
		if(iss(a,b)) continue;
		//printf("unindo %d %d\n", a,b);
		uni(a,b);
		sum+=w;
	
	}
	return sum;
	
	
}


map<string, int> mymap;
int NEXT;
int get(string s){
	int r = mymap[s];
	if(!r) return mymap[s]=NEXT++;
	return r;
}

char str[50], str2[50];
int main (int argc, char const* argv[]){
	int t, n , m;
	int a,b, w;
	sc1(t);
	bool first = 1;
	while(t--){
		if(!first) _
		NEXT=1;
		v.clear(); mymap.clear();
		sc2(n,m);
		init(n);
		fr(i,0,m){
			scanf("%s %s %d", str, str2, &w);
			a = get(str);
			b = get(str2);
			v.pb(edge(a,b,w));
			//printf("%d %d -> %d\n", a,b,w);
		}
		a = go();
		printf("%d\n", a);
		first=0;
	}
	
	
	
	return 0;
}







