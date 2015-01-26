int readDouble(){
	char str[1000]; 
	scanf("%s", str);
	int len = strlen(str);
	int p=len; 
	for(int i =0; i < len; i++) { // primeiro eu acho a posiçao na string q ta o ponto, guardo em p
		if(str[i]=='.') {p=i; break;} // quando encontra o ponto para.
	}
	int r1 = 0; // parte inteira , ou seja: a esquerda do ponto
	int r2 = 0; // parte que tava na parte decimal, ou seja: a direita do ponto
	for(int i =0; i < p; i++){ // parte inteira
		r1 = (str[i]-'0') + 10*r1;
	}
	r1 = r1*100; // como eu tirei a virgula, a parte inteira eh 100 vezes maior
	for(int i = p+1; i < len; i++){
		r2 = (str[i]-'0') + 10*r2;
	}
	printf("r1: %d | r2: %d\n", r1, r2);
	if( len-p == 2) r2 *= 10; // caso especial:  2.3   (ia dar: 23, mas na verdade devia ser 230) 
	return r1+r2; // retorna a soma das duas partes
}