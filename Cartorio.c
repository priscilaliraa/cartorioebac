#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis(string)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" refere-se a write
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" porque estamos apenas atualizando o cadastro, não criando um novo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar() //Início da função deletar nomes
{
	char cpf[40]; //Informação base: cpf
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	remove(cpf); //informação a ser removida
	
	FILE *file;
	file = fopen(cpf,"r"); //o "r" refere-se a read
	
	if(file == NULL) //para quando o sistema não encontrar o cpf digitado
	{
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
	if(file != NULL) //para quando o sistema encontrar e deletar o cpf digitado
	{
		printf("\nUsuário não encontrado no sistema!\n");
		system("pause");
	
	fclose(file);
	}
}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n"); //barra t: parágrafo
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando as escolhas do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			break;
			//fim da seleção
			
		}
	}
}
