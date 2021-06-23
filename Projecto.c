#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>

typedef struct{
    int id_equipe;
    char nome[100];
}Equipe;

typedef struct{
    int id_jogador;
    char nome[100];
    char apelido;
    int nr_golos;
    bool ativo;
    char data_inicio;
    char data_fim;
    int id_equipe;
}Jogador;

/**
PROTOTIPOS DAS FUNCOES DE EQUIPE
*///
FILE *abrirArquivoEquipe(char modo[3]);
int geradorIdEquipe();
void adicionarEquipe();
void imprimirEquipe();

//PROTOTIPOS DAS FUNCOES DE JOGADORES
FILE*abrieArquivoJogador(char modo[3]);
void adicionarJogador();
void imprimirJogador();

int main()
{
    adicionarEquipe();
    imprimirEquipe();
    //imprimirJogador();
    //adicionarJogador();
    return 0;
}



/*DESENVOLVIMENTO DAS FUNCOES DA EQUIPE*/
//FUNCAO QUE ABRE ARQUIVO DE EQUIPES
FILE *abrirArquivoEquipe(char modo[3]){
    FILE *file;
    file = fopen("Equipes.dat", modo);
    if (file==NULL){
        modo = "w";
        file = fopen("Equipes.dat", modo);
    }
    return file;
}


//FUNÇÃO QUE GERA ID DE EQUIPES
int geradorIdEquipe(){
    int id=0;
    Equipe eq;
    FILE *file = abrirArquivoEquipe("rb");
    while(fread(&eq, sizeof(eq),1,file)){
        if(eq.id_equipe>id) id=eq.id_equipe;
    }
    fclose(file);
    return (id+1);
}


//Funcao para cadastrar Equipe
void adicionarEquipe(){
    int tam;
    int i;
    printf("\n\t\t\t\t\tInforme o numero de equipes que deseja adicionar:");
    scanf("%d",&tam);

    Equipe eq[tam];

    for(i=0;i<tam; i++){
        printf("\n\t\t\t\t\tCadastrando a equipd: {%d}",i+1);
        printf("\n\t\t\t\t\t-------------------------------");
        setbuf(stdin,NULL);
        eq[i].id_equipe = geradorIdEquipe();
        setbuf(stdin, NULL);
        printf("\n\t\t\t\t\tNome da equipe: ");
        gets(eq[i].nome);
        //

        //Para escrever os dados de cada equipe no arquivo
        FILE *file = abrirArquivoEquipe("ab");
        fwrite(&eq[i],sizeof(eq[i]),1,file);
        fclose(file);
        printf("\n\n");
    }
    printf("\n\t\t\t\t\tCadastro feito com sucesso!!!\n\n");
}

//FUNÇCÃO QUE IMPRIME EQUIPES
void imprimirEquipe(){
    Equipe eq;
    FILE *file = abrirArquivoEquipe("r+b");
    while(fread(&eq, sizeof(eq),1,file)==1){
        printf("\n\t\t\t\t\tId Id Equipe: %d",eq.id_equipe);
        printf("\n\t\t\t\t\tNome da equipe: %s", eq.nome);
        printf("\n\n");
    }
    fclose(file);
}
//DESENVOLVIMENTO DAS FUNCOES JOGADOR
//FUNCAO QUE ABRE ARQUIVO DE Jogador
FILE *abrirArquivoJogador(char modo[3]){
    FILE *arquivo;
    arquivo = fopen("Jogadores.dat", modo);
    if (arquivo==NULL){
        modo = "w";
        arquivo = fopen("Jogadores.dat", modo);
    }
    return arquivo;
} 
//Funcao para cadastrar Jogador
void adicionarJogador(){
	FILE *arquivo = abrirArquivoJogador("ab"){
        fwrite(&jog[i],sizeof(jog[i]),1,arquivo);
        fclose(arquivo);
		}
	do
	{
		
		printf("Digite o nome:\n");
		scanf("%s",jog[i].nome);
		system("cls");
		
		printf("Digite a idade:\n");
		scanf("%d",&jog[i].apelido);
		system("cls");
		
		printf("Digite a idade:\n");
		scanf("%d",&jog[i].nr_golos);
		system("cls");
		
		printf("Digite a idade:\n");
		scanf("%d",&jog[i].apelido);
		system("cls");
		
		printf("Digite a idade:\n");
		scanf("%d",&jog[i].apelido);
		system("cls");
		
	
		
	}while(op!=2);
	fclose(fp);
    }
//FUNÇCÃO QUE IMPRIME Jogadores
void imprimirJogador(){
    Jogador jog;
    FILE *arquivo = abrirArquivoJogador("r+b");
    while(fread(&eq, sizeof(jog),1,arquivo)==1){
        printf("\n\t\t\t\t\tId Id Jogador: %d",jog.id_jogador);
        printf("\n\t\t\t\t\tNome do jogador: %s", jog.apelido);
        printf("\n\t\t\t\t\tApelido do jogador: %s", jog.nr_golos);
        printf("\n\t\t\t\t\Jogador activo ou nao: %s", jog.ativo);
        printf("\n\t\t\t\t\tData de nascimento do jogador: %s", jog.data_nascimento);
        printf("\n\t\t\t\t\tData de inicio de contrato do jogador: %s", jog.data_inicio);
        printf("\n\t\t\t\t\tdata do fim de contarto do jogador: %s", jog.data_fim);
        printf("\n\n");
    }
    fclose(arquivo);
    /*Funcao para imprimir jogador
void imprimirJogador(){
	
	FILE *arquivo;
	arquivo=fopen("jog.txt","r");
	int i=0;
	Jogador jog[4];
	while(!feof(arquivo)){
		
		fscanf(arquivo,"%s %d",jog[i].nome,&jog[i].id_jogador);
		printf("\n nome:%s \nidade:%d\n",jog[i].nome,jog[i].id_jogador);
		
	}
	fclose(arquivo);
}*/