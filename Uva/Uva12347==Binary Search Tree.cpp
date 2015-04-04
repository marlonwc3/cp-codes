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
set<ii> s;


struct  node {
    int val, l, r;
    node(){}
    node(int _val, int _l, int _r){
        val = _val;
        l = _l;
        r = _r;
    }
    node(int _val){
        val = _val;
        l=-1;
        r=-1;
   }
};

node nodes[10005];
int next=0;
int insert(int val, int id){
  //  printf("ins %d  --- root %d\n", val, id);
    if(id==-1){
      //  printf("achou raiz\n");
        nodes[next] = node(val);
        id = next;
        next++;
        return id;
    }
    if(val > nodes[id].val) {
//        printf("eh maior");
        nodes[id].r = insert(val, nodes[id].r);
        
    }
   else  nodes[id].l = insert(val, nodes[id].l);
    
    return id;
}


void postOrder(int id){
    if(id==-1) return;
    postOrder(nodes[id].l);
    postOrder(nodes[id].r);

    printf("%d\n", nodes[id].val);
}

int main (int argc, char const* argv[])
{
    int val;
    next = 0;
    sc1(val);    
    nodes[0] = node(val);
    next++;
    while(sc1(val) == 1) {
     //  printf("sc1 val %d\n", val);
       insert(val, 0);
    }   
    
    
    
   postOrder(0);
    
    return 0;
}
