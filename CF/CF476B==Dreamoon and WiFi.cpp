#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=a; i < b; i++)
#define pf(a) printf("%d ", a);
#define mp(a,b) make_pair(a,b)
#define pv(v) for(int i=0; i < v.size(); i++) { pf(v[i]); if(i==v.size() -1 ){ _; } }
#define pb(a) push_back(a)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define inf 0x3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int lld;

int fim;
int n;
char str[12];

int a, b;

bool bt(int i, int pos){

	if(i >=  n){

		if(fim==pos) a++;
		else b++;
		return 0;
	}
	char c;
	c = str[i];
	if(c=='+') {
		pos++;
		bt(i+1, pos);
	}
	else if(c=='-'){ 
		pos--;
		bt(i+1, pos);
	} 
	else {
		bt(i+1, pos+1);
		bt(i+1, pos-1);
	}
}


int main (int argc, char const* argv[]) {

	scanf("%s", str);
	n = strlen(str);
	fim =0;
	fr(i,0,n){
		fim += (str[i] =='+') ? 1 : -1; 
	}


	a=b=0;
	scanf("%s", str);
	bt(0,0);
	b+=a;

	double res = (a+0.0)/b;
	printf("%.9lf\n", res);
	
	
	return 0;	
}

