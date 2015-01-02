#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
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
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;

struct  boy{
    int rep, l, r;
    bool morto;
    boy(){morto=0;}
    boy(int _rep, int _l, int _r){
        rep = _rep; l = _l; r = _r;
        morto = 0;
    }
};

int n, s;

boy arr[100005];

void init(int b){
    b=b+1;
    fr(i,0,b){
        arr[i] = boy(i,i-1,i+1);
        //printf("boy[%d]: %d %d %d", i, arr[i].rep, arr[i].l, arr[i].r); _
    }
}

int find(int id){
    if( arr[id].rep != id ) {
        return arr[id].rep = find(arr[id].rep);
    }
    else return id;
}

int findL(int id){
  //  printf("[findL] %d\n", id);
    if(id ==0 || id > n ) return id;
    if( arr[id].morto == 0 ){
     //   printf("Eh le msm\n");
        return id;
    }
    if(arr[id].rep == id ){
      // printf("Eh o rep: %d \n", arr[id].l);
        return findL(arr[id].l);
    }
    return findL( find(id)  );
    
}

int findR(int id){
  //  printf("[findL] %d\n", id);
    if(id ==0 || id > n ) return id;
    if( arr[id].morto == 0 ){
     //   printf("Eh le msm\n");
        return id;
    }
    if(arr[id].rep == id ){
      // printf("Eh o rep: %d \n", arr[id].l);
        return findR(arr[id].r);
    }
    return findR( find(id)  );
    
}


ii uni(int i, int j){
    int repI = find(i);
    int repJ = find(j);
   // printf("rep %d %d\n", repI, repJ);
    for(int k = i; k<=j; k++) {arr[k].morto =1;  }
    //printf("rASA\n", repI, repJ);
    
    arr[repI].morto = arr[repJ].morto =1;
    int la = findL(i), ra = findR(j);
   //  printf("ceh21 \n", repI, repJ);
    int lb = findL(i), rb = findR(j);
   // printf("ceh 1 \n", repI, repJ);
    la = min(la, lb);
    ra = max(ra, rb);
    
    arr[repI].rep = repJ;
    arr[repJ].l = la;
    arr[repJ].r = ra;
    

    
    
    return mp(la, ra);

}


int main (int argc, char const* argv[]) {

    int a,b;
    ii res;
    while(1){
        sc2(n, s);
    //    printf("n s: %d %d\n", n, s);
        if(!n && !s) break;
        init(n);
     //   printf("iniciuado %d\n", n);
        fr(i,0,s){
           sc2(a,b);
          // printf("a: %d b :%d\n", a,b);
           res = uni(min(a,b), max(a,b));
          // printf("res-> %d %d\n", res.st, res.nd);
           if( res.st <= 0 ) printf("*");
           else printf("%d", (res.st) );
           printf(" ");
          
           if(res.nd > n) printf("*\n");
           else printf("%d\n", (res.nd) );
        }
        printf("-\n");
    }
    
    
    return 0;
}

