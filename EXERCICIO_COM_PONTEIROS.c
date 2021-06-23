#include<stdlib.h>




struct Jogador{
	int id_jogador;
	char nome[20];
	int apelido;
	int golos;
//	bool ativo;
//   char data_inicio;
//   char data_fim;
};

void ListaJogador(Jogador*J, int q){
	for(int i=0; i<q; i++){
		printf("%d \n Numero:\n",J[i].id_jogador);
		printf("%s \n Nome:\n",J[i].nome);
		printf("%d \n Apelido\n",J[i].apelido);
		printf("%d \n Golos:\n",J[i].golos);
//		printf("%d \n Activo ou nao:\n",J[i].ativo);
//		printf("%d \n Data de inico de Contrato:\n",J[i].data_inicio);
//		printf("%d \n Data de fim de Contrato:\n",J[i].data_fim);

		
		printf("\n \n");
			
	}
}

void ListaComprar(Jogador*J, int q){
	Jogador jcommaisgolos=J[0];
	
	
 
	for(int i=1; i<q; i++){
		
		if(jcommaisgolos.golos<J[i].golos){
			jcommaisgolos=J[i];
		}	
	}
	printf("%d\n",jcommaisgolos.golos);
	printf("%s\n",jcommaisgolos.nome);
	printf("%d\n",jcommaisgolos.apelido);
	
}


void remover(Jogador*J, int q,int p){
	for(int i=p; i<q; i++){
		J[i]=J[i+1];
	}
}


void adcionar(Jogador*J, int q){
    J=(Jogador*)	realloc(J,(sizeof(Jogador)*6));
	J[5]=J[4];
}


int main(){
	
	int tamanho=5;
	
 Jogador * js= (Jogador*)malloc(sizeof(Jogador)*tamanho);
 
 
  js[0].id_jogador=1;
  js[0].golos=5;
  strcpy(js[0].nome,"Joao");
  //strcpy(js[0].apelido, "Manuel";
  
  js[1].id_jogador=7;
  js[1].golos=40;
  strcpy(js[1].nome,"Ronaldo");
  
  js[0].apelido=19;
  js[2].id_jogador=11;
  js[2].golos=25;
  strcpy(js[2].nome,"Messe");
  
  js[3].id_jogador=4;
  js[3].golos=20;
  strcpy(js[3].nome,"Neymar");
  
  js[4].id_jogador=10;
  js[4].golos=50;
  strcpy(js[4].nome,"Mbape");
  
  remover(js, tamanho-1,2);
 
 tamanho=tamanho-1;
 ListaJogador(js, tamanho);
 ListaComprar(js, tamanho);
 adcionar(js, tamanho);
 
 tamanho=tamanho+1;
 ListaJogador(js, tamanho);
 
	
	
	return 0;
}
