#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define addEdge(a,b) to[z] = b; ant[z] = adj[a]; adj[a] = z++;
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int A[1010];
int T,N;
int memo[1010][1010];
int passotb[1010][1010];
int passo = 0;

int aller(int i, int j){
	int &r = memo[i][j];
	if(passotb[i][j] == passo) return r;
	passotb[i][j] = passo;
	if(i >= j) return r = (i>j)?0:1;
	if(A[i]==A[j]) return r = 1+aller(i+1,j-1);
	else return r = 1+min(aller(i+1,j),aller(i,j-1));
}

int main(){
	memset(passotb,0,sizeof(passotb));
	scanf("%d",&T);
	rp(t,T){
		passo++;
		scanf("%d",&N);
		rp(n,N) scanf("%d",&A[n]);
		printf("Caso #%d: %d\n",t+1,aller(0,N-1));
	}
}
