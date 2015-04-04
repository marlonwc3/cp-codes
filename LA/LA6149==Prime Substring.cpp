#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

bool mark[1000005];

void crive(){
	mark[0]=mark[1]=1; // 0== prime
	fr(i,2,1000005){
		if(mark[i]) continue;
		for(lld j=i*i; j> 0 && j<1000002; j+=i) mark[j]=1;
	}
}

char str[300];
int len;

int num(int a, int b){ // num in str (a,b) 
	int pot = b-a;
	int cont = 0;
	for(int i=a; i <= b; i++, pot--){
		cont += (str[i]-'0')*pow(10.0, pot);
	}
	return cont;

}

int f(){
	int k, res=0;
	fr(i,0,len){
		fr(j,i,len){
			if(j-i+1 >= 6) break; 
			k = num(i,j);
			if(!mark[k]) res = max(res,k);
		}
	}
	return res;
}


int main (int argc, char const* argv[]) {
	crive();
	int res;
	while(1){
		scanf("%s", str);
		len=strlen(str);
		if(len==1 && str[0] =='0') break;
		res = f();
		printf("%d\n", res);
	}
	
	return 0;
}












