#include<stdio.h>


/**

	PAGINA PARA RECURSOS, ALGORITMOS AUXILIARES QUE NAO NECESSARIAMENTE
	PRECISAM ESTAR NA MAIN

*/


char findUnidade(char op[30]){
	char valor;
	for(int i=0;i<strlen(op);i++){
		if(op[i]=='C')
			if(op[i+1]==':')
				valor = 'C';
		else
			if(op[i]=='D' )
				if(op[i+1]==':')
					valor = 'D';				
	}
	if(valor!='C' && valor!='D')
		valor = '0';

	return valor;
}


int possuiSet(char secondPart[30]){
	
	int i = 0, tlp = 0, flag = 0, tlt = 0 ;
	char parte[30], posParte[30];
	
	while(strlen(secondPart)>=i){
		
		if(secondPart[0]==' ' && secondPart[i]!= ' ' && flag != 1){
				parte[tlp++]=secondPart[i];
		}		
		else{
			if(secondPart[i]==' ')
				i++;
					
			posParte[tlt++]=secondPart[i];
			flag = 1;
		}
		i++;
		
	}
	
	/**Como o algoritmo esta capturando tudo e nao esta incluindo o espaço, entao 
	ele fica toC:, toD:*/
	if(strcmp(parte,"DEFAULT") == 0 || strcmp(parte,"default") == 0)
		if(strcmp(posParte,"toC:") == 0 || strcmp("TOC:",posParte) == 0)
			return 1;
		else
			if(strcmp(posParte,"toD:") == 0 || strcmp("TOD:",posParte) == 0)	
				return 2;
			else
				return 120; //ERRO QUE INFORMA QUE NAO É NEM C: E D:	
	else
		if(strcmp(parte,"DELETED") == 0 || strcmp(parte,"deleted"))	
			if(strcmp(posParte,"ON") == 0 || strcmp(posParte,"on") == 0)
				return 3;
			else
				if(strcmp(posParte,"OFF") == 0 || strcmp(posParte,"off") == 0)
					return 4;
				else
					return 340; //ERRO QUE INFORMA QUE NAO É NEM on E off
					
}

char concatenaString(char final[30], char primeiro[30], char segundo[30], char condicao[30]){
	
	int i=0;
	int tl=0;
	if(strcmp(condicao,"junto")==0)
	{
		while(strlen(primeiro)>i)
		{
			final[tl++] = primeiro[i];
			i++;
		}
		i = 0;
		while(strlen(segundo)>i)
		{
			final[tl++] = segundo[i];
			i++;
		}
		
		//printf("Resultado Concat: %s",final);
	}
}





