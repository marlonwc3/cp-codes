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

char res[20][600];

string meda(string s){
    
    if (s=="*.....") return "1";
    if (s=="*.*...") return "2";
    if (s=="**....") return "3";
    if (s=="**.*..") return "4";
    if (s=="*..*..") return "5";
    if (s=="***...") return "6";
    if (s=="****..") return "7";                        
    if (s=="*.**..") return "8";
    if (s==".**...") return "9";
    if (s==".***..") return "0";        
}



string get(int len){
    string r = "", aux, aux2;

    for(int p = 0; p < len  ; p += 3){
       aux = "";
      // printf("p: %d \n", p);
       fr(j,0,3){
             fe(i,p,p+1){
          
                aux2 = res[j][i];
                aux = aux + aux2; 
           }
           
       }
      // printf("pegando %s\n", aux.c_str() );       
       r+= meda(aux);
       
    }
    return r;
}


int put(string line){

    

    fr(i,0,5){
        fr(j,0,600) res[i][j] = 32;
    }
    int k;
      
     int fim = 1;
     for(int i =0; i < 3; i++ ){
        int p = 0;
        for(int j = 0 ; j < line.size(); j++, p+=3){
            k =line[j]-'0';

            if(i==0){
                if(k==1 || k==2 || k == 5 || k == 8){ //*.
                    res[i][p] =  '*';
                    res[i][p+1] = '.';                  
                }
                else if (k==3 || k== 4 || k== 6 || k==7){//**
                      res[i][p] =  '*';
                    res[i][p+1] = '*';                      
                }
                else if(k==9 || k==0){ // . *
                      res[i][p] =  '.';
                    res[i][p+1] = '*';                  
                }
                                                                                                                                              
            }
            if(i==1){
                if(k==2 || k==6 ||k== 9){ //*.
                    res[i][p] =  '*';
                    res[i][p+1] = '.';                  
                }
                else if (k==7 || k== 8 || k== 0){//**
                    res[i][p] =  '*';
                    res[i][p+1] = '*';                      
                }
                else if(k==4 || k==5){ // . *
                    res[i][p] =  '.';
                    res[i][p+1] = '*';                  
                }
                else { // .. 
                    res[i][p] =  '.';
                    res[i][p+1] ='.';                      
                }            
            }
            if(i==2){
             //   printf("botando %d  na linah %d p: %d %d \n",k, i, p , p +1);
                res[i][p]  = '.';
                res[i][p+1] ='.';
             //   printf("colocou %c %c\n", res[i][p], res[i][p+1] );                      
          
            }
            
        }
     
        if(i==2) fim = p;
     }
    // printf("fim %d\n", fim);
     fr(i,0,3){
        res[i][fim-1] = '\0';
     }

}


int main (int argc, char const* argv[])
{
    int d;
    char str[5];
    string line;
    while(1){
        sc1(d); iz(d);
        scanf("%s", str);
        getline(cin, line);
        if(str[0]=='S') {
            getline(cin,line);
          //  printf("%s\n", line.c_str());
            line = put(line);
            fr(i,0,3){
                printf("%s\n", res[i]);
            }
        }
        else if(str[0] =='B' ) {
            mst(res,0);
             int len;
          //   printf("string \n");
             fr(i,0,3){
                gets(res[i]);
              //  printf("%s\n", res[i] );  
             }  
            len = strlen(res[0]);
           // printf("len: %d\n", len);
            line = get(len);
            printf("%s\n", line.c_str() );
        }
    }
    
    
    return 0;
    
    
    
}



