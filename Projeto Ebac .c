#include <stdio.h>//Comunicação com o usuário
#include <stlib.h>//Alocação de memoria por espaço
#include <locale.h>//Alocação de caracteres do tipo texto
#include <string.h>//Criação de strings


int cadastrar() { //Começo da função cadastrar

    //Inicio das variáveis
	char arquivo[120];
	char cpf[11];
	char nome[20];
	char sobrenome[50];
	char cargo[30];


	struct data_nascimento {

		int dia;
		int mes;
		int ano;
	}
    //Fim das variaveis

	printf("Digite seu cpf:\n");//Coleta os dados
	scanf("%s", cpf);//Lê os dados digitados

	strncpy(arquivo, cpf, sizeof(arquivo));//Imprimi os dados na variavel arquivo
	arquivo[sizeof(arquivo) - 1] = 0;//Informa onde termina

	FILE *file;//Cria o arquivo
	file =fopen(arquivo, "w");//Ira abrir o arquivo
	if (!file) {//Validação caso dê erro
	    perror("Erro ao criar arquivo:"); return 1;//Irá imprimir o motivo do erro
	    }
	fprintf(file, "%s \n", cpf);//Irá imprimir dentro da variavel cpf
	fclose(file);//Fecha o arquivo


	printf("Digite o seu nome:\n");//Coleta o dado nome
	fgets(nome, sizeof(nome), stdin);//Irá ler o dado escrito
	nome[strcspn (nome,"\n")] = '\0';//Remove o \n

	file =fopen(arquivo, "a");//Abre o arquivo
	fprintf(file, "%s \n", nome);//Imprime as informações dentro do arquivo
	fclose(file);//Fecha o arquivo

	
	printf("Digite o seu sobrenome:\n");//Coleta os dados
	fgets(sobrenome, sizeof(sobrenome), stdin);//Lê os dados digitados
	sobrenome[strcspn(sobrenome, "\n")] = '\0';//Remove o /n

	file =fopen(arquivo, "a");//Abre o arquivo
	fprintf(file, "%s \n", sobrenome);//Imprimi os dados dentro do arquivo
	fclose(file);//Fecha o arquivo

	
	printf("Digite o seu cargo:\n");//Coleta os dados digitados
	fgets(cargo, sizeof(cargo), stdin);//Lè os dados digitados
    cargo[strcspn(cargo, "\n")] = '\0';//Remove o /n

	
	printf("Digite sua data de nascimento (DD/MM/YYYY):");//Coleta os dados digitados
	scanf("%d/%d/%d", data_nascimento);//Lê os dados digitados

	file =fopen(arquivo, "a");//Abre o arquivo
	fprintf(file, "Data de nascimento: %02d/%02d/%04d", data_nascimento);//Imprimi os dados dentro da variavel data de nascimento
	fclose(file);//Fecha o arquivo
	
	return 0;//Determina o final da função
}
 
 int consultar(){//Começõ da função consultar
     
     //Inicio das variaveis
     char conteudo[200];
     char cpf[11];
     //Fim das variaveis

     printf("Digite o seu cpf:\n");//Coleta os dados digitados
     scanf("%s", cpf);//Lê os dados digitados
     
     FILE *file = fopen(cpf, "r");//Cria o arquivo
      if (file == false){//Validação caso ele dê problema
        printf("Não foi possivel encontrar o cadastro!");//Imprimi Uma mensagem de erro
        system("pause");//Pausa o mensagem por um tempo
        }else{//
          printf("Essas são as informações do usuário:\n");//Imprimi as informações armazenadas
          while(fgets(conteudo, sizeof(conteudo), file) != NULL);//Laço de repetição caso ele continue sendo verdadeiro
          printf("%s",conteudo);//Imprime o conteudo
        }
    fclose(file);//Fecha o arquivo
    printf("\n");//Imprime um espaço
    return 0;//Fim da função cadastrar
 }
 
 int excluir(){//Inicio da função excluir
     
     //Inicio da variaveis
     char cpf[11];
     //Fim das variaveis

     printf("Digite o seu cpf:\n");Coleta os dados digitados
     scanf("%s", cpf);//Lê os dados digitados
     
     remove(cpf);
     
     FILE *file;//
     file =fopen(cpf , "r");
     
     if(file == NULL){
         printf("Usuário não encontrado!");
         system("pause");
     }else{
         printf("Cadastro excluido com sucesso!");
         system("pause");
     }
  
 }
 
 int main{
     
     setlocale(LC_ALL, "portuguese");
     

     int laco = 1;
     int opcao = 0;
     
     while(laco == 1){
         
         printf("Seja bem vindo ao cartório da ebac!\n");
         printf("Escolha uma das opções abaixo.\n");
         printf("\t1 - Cadastrar.\n");
         printf("\t2 - Consultar cadastro.\n");
         printf("\t3 - Excluir cadastro.\n");
         
         scanf("%d", opcao);
         
         switch(opcao){
             
             case 1:// Opção 1
             cadastrar();// Chamada de função
             break;//Para a chamada 
             
             case 2:// Opção 2
             consultar();// Chamada de função
             break;// Para a chamada
             
             case 3:// Opção 3
             excluir();// Chamada de função
             break;// Para a chamada
             
             default:// Entra caso não escolha nenhuma das opções
             printf("Opção inválida, Por favor tente novamente!");// Mensagem de erro
             

            }
     }
 
     return 0;// Fim da função
 }