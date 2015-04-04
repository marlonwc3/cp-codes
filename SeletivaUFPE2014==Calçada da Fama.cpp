#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=(a); i <(b); i++)
#define st first
#define nd second 
#define fe(i,a,b) for(int i=(a); i <=(b); i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


pair<ll, ll> freq[100050];


vii v;
bool mycmp(ii a, ii b){
	if(a.st == b.st ) return a.nd < b.nd;
	return a.st < b.st;
}

vi v2;
vi v3;

int main (int argc, char const* argv[])    {
	int caso;
	sc1(caso);
	ll n, c;
	ll a, b, e;
	
	fe(t,1,caso){
		scanf("%lld %lld", &n, &c);
		v.clear();
		v2.clear();
		v3.clear();
		
		fr(i,0,c){
			scanf("%lld %lld", &a, &b);
			v.pb(mp(a,b));
		}
		scanf("%lld", &e);
		fr(i,0,e){
			scanf("%lld", &a);
			v3.pb(a);
		}
		
		fe(i,0,e+5)  freq[i]=mp(0,0);
	//	sort(v.begin(), v.end(), mycmp);
		sort(v3.begin(), v3.end());
		v2.pb(v3[0]);
		freq[1].nd = 1;
		fr(i,1,v3.size()){
			if(v3[i] == v2.back() ){
				freq[v2.size()].nd++;
			}	
			else{
				v2.pb(v3[i]);
				freq[v2.size()].nd = 1;
			}
		
		}
		
		//fr(i,0,v2.size()){
		
		// printf("%d fre %d  %d\n", v2[i] , freq[i].st, freq[i].nd);
		 
		// }
		//_
	
		
		int r =0;

		fr(i,0,v.size()){
			a = v[i].st, b = v[i].nd;
			//printf("a: %lld | b: %lld\n", a, b);
			int p1 = lower_bound(v2.begin(), v2.end(), a) - v2.begin();
			if( p1 >= v2.size()) continue;
			//if( v2[p1] < a) continue;
			int p2 = upper_bound(v2.begin() + (p1+1) , v2.end(), b) - v2.begin() ;
			//printf("p1 : %d | p2: %d\n", p1, p2);
			if( p2-1 < 0 ) continue;
			if(v2[p2-1] > b) continue;
			
			
			freq[p1+1].st++;
			freq[p2+1].st--;
			//printf();
			
		}
		
	//	fr(i,0,v2.size()){
		
	//	 printf("%d fre %d  %d\n", v2[i] , freq[i].st, freq[i].nd);
		 
	//	 }
	//	_		
		fe(i,1,v2.size()){
			freq[i].st += freq[i-1].st;
		}		
		fe(i,1,v2.size()){
			if(freq[i].st >= 1) r+= freq[i].nd ;
		}
		
		
		printf("Caso #%d: %d\n", t, r);		
		
	}
	
	return 0;
}












