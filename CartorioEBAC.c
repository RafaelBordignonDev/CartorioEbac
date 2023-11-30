#include <stdio.h> //Biblitoeca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar da string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s" ,cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever (write)
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n ");
		system("pause");
		return 0;
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");	
		return 0;
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n ");
		system("pause");
			
	}
	
		return 0;
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");
		
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;	
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;	
		}
		
	}
}
