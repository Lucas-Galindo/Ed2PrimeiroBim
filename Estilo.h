#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
/*

0 - Preto
1 - Azul
2 - Verde
3 - Verde-água
4 - Vermelho
5 - Roxo
6 - Amarelo
7 - Branco
8 - Cinza
9 - Azul claro

*/



void Moldura (int li,int lf,int ci,int cf,int cor,int fundo)
{
	int i=0;
	textcolor(cor);
	textbackground(fundo);
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
	for(i=ci+1; i<cf; i++){
		gotoxy(i,li);
		
		 printf("%c",205);
		gotoxy(i,lf); 
		
		printf("%c",205);
	}
	for(i=li+1; i<lf; i++)
	{
		gotoxy(ci,i); printf("%c",186);
		gotoxy(cf,i); printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void LimpaTela(int LI, int CI, int LF, int CF){

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


void LimpaDif(int li,int lf, int ci, int cf){
	for(int l=li;l<lf;l++){
		for(int c=ci;c<=cf;c++){
			gotoxy(c,l);printf(" ");
		}
	}

	for(int l=li;l<lf;l++){
		for(int c=ci;c<=cf;c++){
			gotoxy(c,l);printf(" ");
		}
	}
}

void limpar(int li,int lf, int ci, int cf){
	for(int l=li;l<lf;l++){
		for(int c=ci;c<=cf;c++){
			gotoxy(c,l);printf(" ");
		}
	}	
}

char menuAluno(){
	LimpaTela(6,3,22,58);
	
	gotoxy(5,9);printf("[A]Alterar Aluno");
	gotoxy(5,10);printf("[B]Relatorio Aluno");
	gotoxy(5,11);printf("[C]Buscar Aluno");
	gotoxy(5,12);printf("[D]Excluir Aluno");
	gotoxy(5,13);printf("[E]Operacao");
	gotoxy(5,14);textcolor(4);printf("[F]Arquivo -> Lista"); //Criar Caixas de Aluno
	gotoxy(5,16);textcolor(7);printf("Opcao: ");
	return toupper(getche());
	
}

char menuDisc(){
LimpaTela(6,3,22,58);
	gotoxy(5,9);printf("[A]Alterar Notas");
	gotoxy(5,10);printf("[B]Excluir Notas");
	gotoxy(5,11);printf("[C]Relatorios");
	gotoxy(5,12);printf("[D]TXT - Binario");
	gotoxy(5,13);printf("Opcao: ");
	return toupper(getche());
}

void ManualDEV(){
	
	LimpaTela(6,3,22,58);
	gotoxy(5,8);printf("Caso voce esteja pegando o codigo pela primeira vez");
	gotoxy(5,9);printf("Funcao: ");
	gotoxy(5,10);textcolor(4);printf("ARQUIVO.H ->");textcolor(7);printf("Manipulacao dos arquivos texto e binario");
	gotoxy(5,11);textcolor(4);printf("ESTILO.H ->");textcolor(7);printf("Manipulacao e ferramentas");
	gotoxy(5,12);printf("para edicao de tela");
	gotoxy(5,13);textcolor(4);printf("Estrutura_AluDisc.h ->");textcolor(7);printf("Localizacao das structs");
	gotoxy(5,14);printf("do programa e funcoes auxiliares relacionadas a lista");
	gotoxy(5,15);printf("As alteracoes devem respeitar a localidade ");
	gotoxy(5,16);printf("dos codigos, a main tem prioridade em execucao");
	gotoxy(5,17);printf("Se por acaso voce esta desenvolvendo a interface,");
	gotoxy(5,18);printf("acomode os menus dentro da main no arquivo Estilo.h");
	getch();
	
}

char menuCreate(){
	LimpaTela(6,3,22,58);
	gotoxy(6,2);printf("Field Name");
	gotoxy(19,2);printf("Type");
	gotoxy(29,2);printf("Width");
	gotoxy(38,2);printf("DEC");
	
	
	//gotoxy(3,4);printf("codigo");
	
	
	
	
	return toupper(getche());
	
}


char menu(){
	
	//Moldura(1,24,1,79,4,0);//Quadrado externo
	//Moldura(2,4,2,78,7,0);//Titulo
	//Moldura(5,23,60,78,7,0);//Bloco lateral
	
	//Moldura(22,23,2,59,7,0);//Bloco - Instrução
	
	//Moldura(5,23,2,59,7,0);//Bloco - Dentro
	
	//gotoxy(32,3);textcolor(4);printf("# Trabalho de ED - II #");
	/*gotoxy(62,8);textcolor(7);printf("[A]___Aluno ");
	gotoxy(62,10);textcolor(7);printf("[B]___Materias");
	gotoxy(62,12); textcolor (7); printf("[C]___Manual Dev");
	gotoxy(62,14);printf("[D]___Outros");
	gotoxy(62,16);textcolor(4);printf("[ESC]___Sair");
	gotoxy(4,21); textcolor(7); printf("Selecione: ");*/
	
	
	
	return toupper(getche());
	
}



