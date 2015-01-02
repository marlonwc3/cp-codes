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
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
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
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

bool mark[40][120];
int afim[40][120];

bool mycmp (ii a, ii b){
	int x = a.st, y = a.nd;
	int z = b.st, w = b.nd;
	if(afim[x][y-1] < afim[z][w-1] ) return 1;
	if(afim[x][y-1] > afim[z][w-1] ) return 0;
	if(afim[x][y] < afim[z][w] ) return 1;
	if(afim[x][y] > afim[z][w] ) return 0 ;

	if(x==z) return y < w;
	return x < z;	
}

vii v;
int main (int argc, char const* argv[]) {
	int r, c, z, p;	
	int x, y;
	char ch, ch2;
	char str[100];
	while(1){
		sc2(r,c);
		if(!r && !c ) break;
		mst(mark, 0);
		mst(afim, 0);
		v.clear();
		sc1(p);
		while(p--){
			scanf("%s", str);
			ch = str[0];
			int len  =strlen(str);
			if(len == 3) y = (str[1]-'0')*10 + (str[2]-'0');
			else  y = str[1]-'0';
			x = ch-'A' +1 ;
			scanf("%s", str);
			ch2 = str[0];			
			if(ch2=='-') mark[x][y-1] =1;
			if(ch2 == '+' ) mark[x][y] = 1; 
		}
		
		sc1(z);
		fr(i,0,z){
			scanf("%s", str);	
			ch = str[0];
			x = ch-'A' + 1;
			int len  =strlen(str);
			if(len == 3)  y = (str[1]-'0')*10 + (str[2]-'0');
			else y = str[1]-'0';	
			if(!mark[x][y-1]) afim[x][y-1]++;
			if(!mark[x][y]) afim[x][y]++;
			v.pb(mp(x,y));
		}
		
		sort(v.begin(), v.end(), mycmp);
		bool ok = 1;
		fr(i,0,z){
			x = v[i].st, y = v[i].nd;
			if(mark[x][y-1] &&  mark[x][y] ) ok = 0;
			else if(mark[x][y-1])  mark[x][y] = 1;
			else if (mark[x][y]) mark[x][y-1] =1;
			else {
				if( afim[x][y-1] > afim[x][y] ) mark[x][y] = 1;
				else
				 mark[x][y-1] = 1;				
			}
		}
		
		if(ok) printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}






