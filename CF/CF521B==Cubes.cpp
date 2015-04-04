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

const ll MOD = ll(1000000009);

int n;
set<ii> todos;
set<int> myset_number;
vii v;
int numbers[100005];



int getbottom(ii p){
	if(!todos.count(p)) return 0;
	int r = 0;
	fe(i,-1,1){
		r += todos.count(mp(p.st + i, p.nd -1));
	}
	return r;
}

int getc(ii p){
	int r = 0;
	fe(i,-1,1){
		r += getbottom(mp(p.st + i, p.nd + 1) ) == 1;
	}
	return r;
}

map<ii, int> mymap;
map<int, ii> map_number;
int main (int argc, char const* argv[]) {
	ll M;
	sc1(n);
	M = n;
	ii p;
	int x, y ;
	fr(i,0,n){
		sc2(x,y); 
		p = mp(x,y);
		//printf("x: %d | y: %d\n", x, y);
		mymap[p] = i;
		map_number[i] = p;
		todos.insert(p);
		v.pb(p);
	}
	fr(i,0,v.size()){
		if(getc(v[i]) == 0 ) {
			myset_number.insert(mymap[v[i]]);
			//printf("pode: %d %d | num %d \n", v[i].st, v[i].nd, mymap[v[i]] );
		}
	}
	bool turn = 1;
	int no, no2;
	ii p2;
	ll res=  0;
	while(n--){
		if(turn) no = *(myset_number.rbegin());
		else no = *(myset_number.begin());
		res = (M*res)%MOD + no;
		myset_number.erase(no);		
		p = map_number[no];
		todos.erase(p); 
		//printf("NO: %d\n", no);
		fe(i,-2,2){
			p2 = mp(p.st + i, p.nd);
			if(todos.count(p2) && getc(p2) != 0){
				no2 = mymap[p2];
				myset_number.erase(no2);
			}
		}
		
		fe(i,-1,1){
			p2 = mp(p.st + i, p.nd-1);
			if(todos.count(p2) && getc(p2) == 0){
				no2 = mymap[p2];
				myset_number.insert(no2);
			}		
		}
		turn = !turn;
	}
	
	printf("%I64d\n", res);
	
	
	
	
	
	return 0;
}



