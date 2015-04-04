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


int todos[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i' };
int N;
string space(int k){
	k*=2;
	string str = "";
	while(k>0) { str += " "; k--; }
	return str;
}

void pf(){
	printf("%c", todos[0]);
	fr(i,1,N) printf(",%c", todos[i]);
}

string go(int p){

	string str = "", aux1, aux2;

	if(p>=N) {

		str += space(p) + "writeln("; aux1 = todos[0]; str += aux1;
		fr(i,1,N) {
			aux1 = todos[i];
			str += ","+aux1;
		}
		str += ")\n";
		return str;
	}
	if(p==0) return go(p+1);
	
	aux1 = todos[p], aux2 = todos[p-1];
	str += space(p) + "if " + aux2 +" < " +aux1 +" then\n";
	str += go(p+1);
	swap(todos[p], todos[p-1]);	
	for(int i = p-1; i>0; i--){
		aux1 = todos[i], aux2 = todos[i-1];
		str += space(p) + "else if " + aux2 +" < " +aux1 +" then\n";
		str += go(p+1);		
		swap(todos[i], todos[i-1]);	
	}
//	aux1 = todos[0], aux2 = todos[p-1];
	str += space(p) + "else\n" + go(p+1);
	fr(i,0,N-1){ swap(todos[i], todos[i+1]); }
	
	return str;
}

string pd[9];

string vai(int n){
	N = n;
	if(n==1) return space(1)+"writeln(a)\n";
	else{
		return go(1);
	
	}

}


int main (int argc, char const* argv[]){
	int M;
	sc1(M);
	bool first = 1;
	string str;
	fe(i,1,8){
		pd[i] = vai(i);
	}
	
	
	
	while(M--){		
		if(!first) _
		sc1(N);
		fr(i,0,N) todos[i] = 'a'+i;
		
		printf("program sort(input,output);\nvar\n");
		pf();
		printf(" : integer;\nbegin\n");
		str = space(1); printf("%s", str.c_str());
		printf("readln("); pf(); printf(");\n");
		
		str = pd[N];
		printf("%s", str.c_str());
			
		printf("end.\n");
		
		
		
		first =0;
	}


	return 0;
}















