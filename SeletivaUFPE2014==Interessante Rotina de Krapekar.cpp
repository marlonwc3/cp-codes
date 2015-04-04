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
typedef vector<ll> vll;

int cmp(int a, int b ){
	return a > b;
}

int maior_menor(int k, bool menor){

	vi v;
	int cnt = 0;
	while(k) {
		v.pb(k%10);
		k/=10;
		cnt++; 
	}
	while( cnt < 4 ) {
		cnt++; v.pb(0);
	}


		
	if(menor) sort(v.begin(), v.end());
	else sort(v.begin(), v.end(), cmp);
	int res = 0;
	fr(i,0,v.size()){
		res = 10*res + v[i];
	}
	return res;
}



int foo(int x ){
	int cnt = 0;
	
	while ( x != 6174 ){
		int maior = maior_menor(x, false);
		int menor = maior_menor(x, true);
		x = maior - menor;
		cnt++;
		if(!x) return -1;		
	}
	return cnt;
}





int main (int argc, char const* argv[]) {
	string line;
	int caso;
	sc1(caso); getline(cin,line);
	bool mark[30];
	fe(t,1,caso){
		getline(cin,line);
		bool ok = 1;
		fr(i,0,20) mark[i] = 0;
		if(line.length() <= 4 ){
			while(line.length() < 4 ){ 
				string aux;
				aux = '0';
				line = aux + line;
				int l = line.length();
				//printf("line: %s | line l %d\n", line.c_str(),  l);
			}
		} 
		else  {
		 ok =0;
		 
		}
		int x = 0;
		if(ok){
			int dif = 0;
		//	printf("line: %s\n", line.c_str() );
			fr(i,0,4){
				if(!mark[ line[i]-'0' ]) {dif++; mark[line[i]-'0'] = 1 ;}
				x = 10*x + line[i]-'0';
			}
			//printf("dif: %d\n", dif);
			if(dif >= 2) {
				x = foo(x);	
			}
			else{
				ok = 0;
			}
		}
		if(!ok) printf("Caso #%d: -1\n", t);
		else printf("Caso #%d: %d\n", t, x);
		
		
		
	
	}
	
	
	return 0;
}








