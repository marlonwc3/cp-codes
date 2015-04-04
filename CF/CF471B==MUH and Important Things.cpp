#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define mp(a,b) make_pair(a, b)
using namespace std;

/*
5 (n >= 2000)
1 3 1 1 4 
0 1 2 3 4

vetor de vetores

1: 0, 2, 3  (permuta aqui) 
3: 1 (permuta aqui) 
4: 4 ( permuta aqui )

mapping de vetores 

*/


typedef vector<int> vi;
vi keys;
map<int, vi> mvi;
int n=3, cont=0;
vi res;

void pv(){
    int s = res.size();
    for(int i=0; i <s; i++ ){
        printf("%d ", (res[i]+1) );
        if(i!=s-1) printf(" ");
    }
    if(s > 0 ) printf("\n");
}

bool bt(int k){
    if(cont>=3) return 0;
    if(k>=keys.size() ) {
        pv();
        cont++;
        return 0;
    }
    int key = keys[k];
    vi v = mvi[key];
    int s = v.size();
    sort(v.begin(), v.end());
    do{
        if(cont>=3) break;
        for(int i=0; i < s; i++){res.push_back(v[i]);}  
        bt(k+1);
        for(int i=0; i < s;i++ ) res.pop_back();    
    } while(next_permutation(v.begin(), v.begin()+s));
}


int main (int argc, char const* argv[]) {
    scanf("%d", &n);
    int k; vi v;
    for(int i=0; i< n; i++){
        scanf("%d", &k);
        if(!mvi.count(k) ) {
            keys.push_back(k);
            v = vector<int>();
            v.push_back(i);
            mvi.insert(mp(k, v) );
        }
        else {
            mvi[k].push_back(i);
        }
    }
    
    sort(keys.begin(), keys.end());
    
    int res=1, s;
    for(int i =0;  res<=3 && i < keys.size(); i++){
        s =mvi[keys[i]].size();
        if(s == 2 ) res*=2;
        if(s>=3) res = 3;
    }
    if(res< 3) printf("NO\n");
    else {
        printf("YES\n");
        bt(0);
    }
    
    return 0;
}
