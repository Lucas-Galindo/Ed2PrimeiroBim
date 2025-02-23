#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>


#include "Estilo.h"

#include "Recursos.h"

/**
	PAGINA PRINCIPAL
*/


/**
	AINDA FALTA - COLOCAR O PDADOS , PATUAL E A LISTA DE STATUS
	
	IMPLEMENTAR PILHA QUE SEGURE O QUE FOI INPUTADO, 
	COMO VOU SABER QUEM E DE QUEM, ESTOU DANDO USE EM QUEM
	CASO NO MEIO DO PROCESSO TENHA UM OUTRO USE, FAZER QUE DESEMPILHE TUDO
	E USE O OUTRO COMANDO
*/


struct tpCampos{
	char nome[30];
	char type[2];
	int width;
	int dec;
}; typedef struct tpCampos TpCampo;

struct status{
	TpStatus info;
	struct status *ptr;
	
};typedef struct status Status;


struct tpData{
	int d,m,a;
}; typedef struct tpData TpData;

struct tpHora{
	int h,m;
}; typedef struct tpHora TpTempo;

struct tpArgs{
	char nome[30];
	TpData data;
	TpTempo tempo;
}; typedef struct tpArgs TpArgs;

struct args{
	struct args *ant, *prox;
	TpArgs info;
	TpCampo *pCampo;
	Status *pStatus;
	
};typedef struct args lista_args;


struct unidade{
	char nome[3];
	struct unidade *top, *bottom;
	lista_args *args;
}; typedef struct unidade Unidade;

struct campos{
	struct campos *prox;
	 TpCampo info;
	//pdados e patual
}; typedef struct campos Campos;



void clear(){


	int LI = 5, CI= 3, LF = 30, CF  = 20;
	int i, j;
	textbackground(0);
	for(i=LI;i<=LF;i++){
		for(j=CI;j<=CF;j++){
			gotoxy(j, i);
			printf("%c", 32);
		}
	}
	textbackground(0);
}


//////////// INSERCAO //////////////

void inserirArgs(lista_agrs **lista, TpArgs A){
	lista_args *novo;
	novo = (lista_args*)malloc(sizeof(lista_args));
	novo->info = A;
	novo->pCampo = NULL;
	novo->pStatus = NULL;
	novo->ant=novo->prox=NULL;
	
	
	if(*lista == NULL)
		*lista = novo;
	else
	{
		//Colocando no final da lista sempre
		lista_args *aux = *lista;
		while(aux->prox!=NULL)
			aux=aux->prox;
				
		novo->ant = aux;
		aux ->prox = novo;
	}	
	
}


///////////////////////////////////


///////////OPERACAO/////////////

void createArgs(Unidade **lista, char tableName[30]){
	/**
	Usando biblioteca time.h para pegar a hora a data direto do sistema
	*/
	struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    
    TpArgs A;
	
	//printf("\n%c",carac);
	
	//char dia[2], mes[2], ano[4];
		
	/** Convertendo o dia extraido para string*/
		
	/*sprintf(dia,"%d",p->tm_mday);
	sprintf(mes,"%d",p->tm_mon + 1);
	sprintf(ano,"%d",p->tm_year + 1900);*/
	//printf("%s",dia);
	
	
	/** Colocando as variaveis de data int*/
	A.data.d = p->tm_mday;
	A.data.m = p->tm_mon + 1;
	A.data.a = p->tm_year + 1900;
	
	/** Colocando as variaveis de tempo (hora e minuto) int*/
	A.tempo.h = p->tm_min;
	A.tempo.m = p->tm_sec;
	
	
	//printf("%d/%d/%d",A.data.d,A.data.m,A.data.a);
	//printf("%d:%d", A.tempo.h,A.tempo.m);
	
	//char formatData[20] = {dia[2]+'/'+mes[2]+'/'+ano[4]};
	
	//strcpy(A.data,dia[2]+'/'+mes[2]+'/'+ano[4]);
	//printf("\n%s",A.data);

   // printf("Data: %d/%d/%d\n", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900);
    //printf("Hora: %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
	
	strcpy(A.nome,tableName);
	
	lista_args *listaA = *lista->args;

	inserirArgs(&*lista->args, A);
}



void createCampos(){

	menuCreate();
	
	/**
		Ao completar a sequencia de titulos e valores, deve se apertar enter  
		e ele cria ou nao mais campos dentro daquele dbf
	*/
	
	/*char nameField[30],typeField[30];
	int widthField,decField;*/
	
	TpCampo C;
	
	
	int i=1; char esc=0;
	int x = 3, y = 4;
	while(esc!=27){
		
		gotoxy(3,y);printf("%d",i);
		gotoxy(6,y);fflush(stdin);gets(C.nome);	
		gotoxy(18,y);fflush(stdin);gets(C.type);
		gotoxy(30,y);scanf("%d",&C.width);
		gotoxy(39,y);scanf("%d",&C.dec);
	
	
		/**
		 Guardar dentro da lista
		*/
		
		
		
		y+=2;
		i++;
		
		esc = getch();
	}
	
}


int direcionaComando(Unidade **lista, char *unid, char firstPart[30], char secondPart[30], char thirdPart[30], char fourthPart[30]){
	
	/**
	 	PODE SER QUE OS DOIS ULTIMOS PARAMETRO ESTEJAM VAZIOS {}. NAO TEM PROBLEMA
	*/
	printf("\nPrimeira parte: %s", firstPart);
    printf("\nSegunda parte: %s", secondPart);
    printf("\nTerceira parte: %s", thirdPart);
    printf("\nQuarta parte: %s", fourthPart);
    
	/*int value;   
	if(strcmp(secondPart,"DEFAULT") == 0)
		 value = 0;
	else
		value = 1;
		
	printf("\n%d",value);*/	
	
	
	if(strcmp(firstPart,"SET") == 0 && strcmp(secondPart,"DEFAULT") == 0)
	{
	
		//printf("\nENTROU default");
			
			
		/**
			Guardar na memoria o diretorio(unid), pq quando termina a função o unid vira lixo na pilha de variavel
		*/
		
		/*char *unid;
		if(inicio == 0){		
			unid = (char*)malloc(sizeof(char));
		}
		unid = (char*)malloc(sizeof(char));*/

			//printf("\n%c",*unid);
			if(strcmp(fourthPart,"C") == 0){
				
				*unid = 'C';
				//printf("\n%c",*unid);
				return 0;
			}	
			else
				if(strcmp(fourthPart,"D") == 0){
					
					*unid = 'D';
					//printf("\n%c",*unid);
					return 0;
				}
				else{
		
					*unid = '#';
					//printf("\n%c",*unid);
					return 101;	//Sinalizador de erro;
				}	
		
		//strcpy(unid,fourthPart);
		//printf("\nUNIDADE: %c",unid);
		
	}		
	if(strcmp(firstPart,"CREATE")==0)
	{
		//clear();
		createArgs(&lista, secondPart);
	}
	else
		if(strcmp(firstPart,"quit") ==0 || strcmp(firstPart,"QUIT")==0)
		{
			return -1;
		}
		else
		{
			if(strcmp(firstPart,"DIR") ==0 || strcmp(firstPart,"dir")==0)
			{
				
			}
			else
			{
				if((strcmp(firstPart,"LIST") == 0 || strcmp(firstPart,"list") ==0) && (strcmp(secondPart,"STRUCTURE") == 0 || strcmp(secondPart,"structure")==0 ))
				{
						
				}
				else
				{
					if(strcmp(firstPart,"LIST") == 0 || strcmp(firstPart,"list") ==0)
					{
						
					}
					else
					{
						if(strcmp(firstPart,"APPEND") == 0 || strcmp(firstPart,"append") ==0)
						{
							
						}
						else
						{
							if(strcmp(firstPart,"CLEAR") == 0 || strcmp(firstPart,"clear") ==0)
							{
								clear();
							}
							else
							{
								if(strcmp(firstPart,"LOCATE") == 0 || strcmp(firstPart,"locate") ==0)
								{
									
								}
								else
								{
									if(strcmp(firstPart,"GOTO") == 0 || strcmp(firstPart,"goto") ==0)
									{
										
									}
									else
									{
										if(strcmp(firstPart,"DISPLAY") == 0 || strcmp(firstPart,"display") ==0)
										{
											
										}
										else
										{
											if(strcmp(firstPart,"DISPLAY") == 0 || strcmp(firstPart,"display") ==0)
											{
												
											}
											else
											{
												if(strcmp(firstPart,"EDIT") == 0 || strcmp(firstPart,"edit") == 0)
												{
													
												}
												else
												{
													if(strcmp(firstPart,"DELETE") == 0 || strcmp(firstPart,"delete") ==0)
													{
														
													}
													else
													{
														if((strcmp(firstPart,"SET") == 0 || strcmp(firstPart,"set") ==0) && (strcmp(secondPart,"DELETED") == 0 || strcmp(secondPart,"deleted")))
														{
															
														}
													}
												}
											}
										}
									}

								}
							}
						}
					}
				}
				
			}
		}
		
}

/*
int identificaComando(){
	
	int i=0,tlc=0,tlt=0, tls=0, tlSUB = 0;
	char firstPart[30] = {}, secondPart[30] = {}, posEspaco[30] = {}, quartaSubString[30] = {};
	char linha[30];
	int space = 0, flag = 0;
	
	secondPart[0] = ' ';
	
	gets(linha);
	fflush(stdin);
	
	while(strlen(linha)>=i){
		//printf("%c",linha[i]);
			
		if(secondPart[0]==' ' && linha[i]!= ' ' && flag != 1){
			firstPart[tlc++]=linha[i];
		}		
		else{
			if(linha[i]==' '){
				i++;
				space++;
			}	
			if(space>=2)
			{
				posEspaco[tls++] = linha[i];
				
				if(space == 3){ //Caso há uma 4 string, como no caso do set default
					quartaSubString[tlSUB++] = linha[i];
				}
			}
			else
			{
				secondPart[tlt++]=linha[i];
				flag = 1;
			}
					
		}
		i++;
					
	}
		/**
			A intenção da pilha é para empilhar as operações que estao sendo feitas
			para aquele determinado database
		*/
		
		//Pilha1 *P=NULL;
		//Push(&P,firstPart,unid);
		
		//printf("\n%s",primeiraParte);
		//printf("\n%s",segundaParte);
	
		//return direcionaComando(firstPart, secondPart, posEspaco, quartaSubString);
		
//}



int identificaComando(char *unid, char linha[30], Unidade **lista){
	
	int i=0,tlc=0,tlt=0, tls=0;
	char firstPart[30] = {}, secondPart[30] = {}, thirdPart[25] = {}, fourthPart[25] = {};
	char linhaMaiscula[30];
	int space = 0, flag = 0, spaceCount = 0; 
	int j, tlt3 = 0, tlSUB = 0;
	
	secondPart[0] = ' ';
	
	//gets(linha);
	//fflush(stdin);
	
	/** TRANSFORMANDO A LINHA EM MAISCULO*/
	for ( j = 0; j < strlen(linha); j++) {
        linhaMaiscula[j] = toupper(linha[j]);
    }
    linhaMaiscula[j] = '\0';
	
	//printf("\n%s",linhaMaiscula);
	
	 while (linhaMaiscula[i] != '\0')
	 {
    	// Ignora espaços em branco
	    if(linhaMaiscula[i] == ' ' && flag != 1)
		{
	        spaceCount++;
	        flag = 1;
	    } 
		else 
			if(linhaMaiscula[i] != ' ')
			{
		        flag = 0; // Redefine a flag quando encontra um caractere que nao e espaço
		    }
		    if(spaceCount == 0)
			{
		        firstPart[tlc++] = linhaMaiscula[i];
			}
		    else 
				if(spaceCount == 1)
				{
					if(linhaMaiscula[i] == ' ') //Se tirar esse if, quebra direcionaComando().
						i++;
		        	secondPart[tlt++] = linhaMaiscula[i];
		    	}
			    else 
					if (spaceCount == 2)
					{
						if(linhaMaiscula[i] == ' ')
							i++;
			        	thirdPart[tlt3++] = linhaMaiscula[i];
			   		}
			    	else
					{
						if(linhaMaiscula[i] == ' ')
							i++;
				        fourthPart[tlSUB++] = linhaMaiscula[i];
				        
			    	}
		
	    i++;
	}

	

	//Adiciona o caractere nulo no final de cada substring para indicar o fim da string
	
	tlt+=5;
	firstPart[++tlc] = '\0';
	secondPart[++tlt] = '\0'; 
	thirdPart[++tlt3] = '\0'; 
	fourthPart[++tlSUB] = '\0';

    
    // Finaliza as strings com o caractere nulo
    
	
	/*printf("\nPrimeira parte: %s", firstPart);
    printf("\nSegunda parte: %s", secondPart);
    printf("\nTerceira parte: %s", thirdPart);
    printf("\nQuarta parte: %s", fourthPart);*/
	
	
		
		//Array com todas as substrings, facilita uso. Teste.
		//char arraySubString[30] = {firstPart[30],'-',secondPart[30],'-',thirdPart[30],'-',fourthPart[30],'0'};	
		//printf("\n%s",arraySubString);
		
	
	return direcionaComando(&lista, unid, firstPart, secondPart, thirdPart, fourthPart);
		
}




int SET_DIRETORIO(Unidade **C, Unidade **D){
	
	char op[30] = {};
	
	gets(op);
	fflush(stdin);
		
	if(strcmp(op,"QUIT") ==0 || strcmp(op,"quit")==0)
		return -1;
	else{
		if(strcmp(op,"SET DEFAULT TO C:") == 0 || strcmp(op,"SET DEFAULT TO D:") == 0 || strcmp(op,"set default to C:") == 0 || strcmp(op,"set default to D:") == 0)
		{
			char unidadeEscolhida = findUnidade(op);
				
			if(unidadeEscolhida=='0')
				printf("UNITY DONT EXISTS\n");
			
				
					//identificaComando(&C);
				
					//identificarComando(&D);				
								
		}
		else{
			
			printf("SET DEFAULT REQUIRED");
			printf("\n");
				
			return 0; 
			
		}
		
	}
		
}


void operacao(Unidade **lista){
	
	int value; char linha[30];
	
	char *unid;
	unid = (char*)malloc(sizeof(char));
	gets(linha);
	fflush(stdin);
	while(value!=-1 ){
		
		
		if(strcmp(linha," ")!=0 && strcmp(linha,"/0")!=0)
			value = identificaComando(unid, linha, &lista);
		
		if(value == 101)
			printf("\nERRO 101 - direcionaComando() - ERRO SET DEFAULT TO\n");
					
		gets(linha);
		fflush(stdin);
	}
		
}

//////////////////////////////////////////////////////

////////////INICIALIZAR VARIAVEIS/////////////

void Inicio(Unidade **lista, char name[3]){
	
	
	Unidade *unid = (Unidade*)malloc(sizeof(Unidade));
	strcpy(unid->nome,name);
	unid->top=NULL;
	unid->bottom=NULL;
	unid->args = NULL;
	
	if(*lista == NULL){
		*lista = unid;
	}
	else{
		Unidade *aux = *lista;
		where(aux->bottom!=NULL)
			aux=aux->bottom;
		
		aux->bottom = unid;	
	}
	
}

////////////////////////////////////////////

/**
	PENSAR EM UM JEITO DE VOLTAR A FUNÇÃO PRA FINALIZAR PROCESSO
*/

int main(){
	Unidade *C=NULL;
	
	Inicio(&C,"C:");
	Inicio(&C,"D:");
	
	//create();
	operacao(&C);
	
	free(C);
}
