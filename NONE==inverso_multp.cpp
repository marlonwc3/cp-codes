/*
Encontrar x tal que ax = 1 mod P
*/
int inv(int a){
  int x;
  for(x=1;x<=P;x++){
    if((a*x)%P==1)
      return x;
  }
}

/*
Durante a busca do inverso multiplicativo de a, podemos encontrar também o inverso multiplicativo de x. 
*/
int inverso[P+1];
int inv2(int a){
  int x;
  if(inverso[a]!=0) return inverso[a];
  else{
    for(x=1;x<=P;x++){
      if((a*x)%P==1){
        inverso[a] = x;
        inverso[x] = a;
      }
    }
    return inverso[a];
  }

}

/*
Pequeno Teorema de Fermat
ap-1= 1 mod p
Assim, 
a*ap-2=1 mod p
inv(a) = ap-2 mod p
*/
/*Pequeno Teorema de Fermat (a^P-1) = 1 mod P*/
int inv3(int a){
  int i;
  long long int x;
  x=1;
  for(i=1;i<=P-2;i++) x = (x*a)%P;
  return x;
}

//Exponenciação Rápida
int fastexp(int a,int b){
  long long int x;
  if(b==0) return 1;
  if(b==1) return a;
  if(b%2==0){
    x = fastexp(a,b/2)%P;
    return (x*x)%P;
  }else{
    return (a*fastexp(a,b-1))%P;
  }
}

int inv4(int a){
  return fastexp(a,P-2);
}
/*
Algoritmo de Euclides Estendido para resolver equaçoes diofantinas
ax + by = 1
ax = 1 mod b
*/
int mdc(int  a, int b, int *x, int *y) {
  int xx, yy, d;
  if(b==0) {
    *x=1; *y=0;
    return a;
  }
  d = mdc(b, a%b, &xx, &yy);
  *x = yy;
  *y = xx - a/b*yy;
  return d;
}

int inv5(int a){
  int x,y,d;
  d = mdc(a,P,&x,&y);
  if(x<0){
    x = x+P;
  }
  return x;
}