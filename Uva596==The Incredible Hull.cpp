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

typedef int T;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { 
  	if(x == rhs.x ) return y < rhs.y;
  	return x > rhs.x;
  	//return make_pair(y,x) < make_pair(rhs.y,rhs.x); 
  }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
  
  void pf(){
   	//printf("(%.0lf, %.0lf) ", x, y); 
   	printf(" (%d,%d)", x, y); 
   	
   }
  
};
T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());	 
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}




int mycmp(PT a, PT b){
	if(a.x == b.x) return a.y < b.y;
	return a.x > b.x;

}



char line[300];
vector<PT>  pts;
void pf(){
	fr(i,0,pts.size() ) pts[i].pf(); 
	_	
}
char ch; int id, n;
char str[30000]; int sz;
int main (int argc, char const* argv[]){
	bool first = 1;
	int x, y;
	while(1){
		gets(line);
		if( ( line[0]=='S' && !first )  || line[0] == 'E' ) {
//			pf();
			ConvexHull(pts);
//			sort(pts.begin(), pts.end(), mycmp);
//			printf("Convex\n	");
			fr(i,0,sz) printf("%c", str[i]);
			printf(" convex hull:\n");
			pf();
		} 
		if(line[0]=='E') break;
		if(line[0]=='S'){
			sz = 0;
			for(int i = 2; line[i]; i++, sz++){
				str[sz] = line[i];
			}
			
			
			
			
			pts.clear();
			first = 0;
		}
		if(line[0]=='P'){
			int it  = 0;
			char *pch = strtok(line , " ");
			for( ; it < 2; it++, pch = strtok(NULL, " " ) ){
				if(it==1) sscanf(pch, "%d", &n);
			}
			it= 0;
			for(int i = 0; i<n && pch; pch = strtok(NULL, " " ) ){
				if(it==0) {sscanf(pch, "%d", &x); it=1;}
				else {
					sscanf(pch, "%d", &y); 
					pts.pb(PT(x,y)); it=0;
					i++;
				}
			}
		
		}	
	}
	
	
	
	
	
	return 0;
}



















