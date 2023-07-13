#include <stdio.h> //biblioteca de comunica��o pelo usuaria
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro () // fun��o responsavel por cadastrar os usuarios no sistema 
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser adastrado: "); //coletando informa��es do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: " );
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file  = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	}	

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //cria arquivo 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o aquivo, N�o localizado...!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");
		
		
		
}
	
int deletar()
	{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //cria arquivo 
	file = fopen( cpf,"r");
	
	if(file == NULL)
	{
		printf("O cpf n�o se encontra no nosso sitema! .\n");
		system("pause");
	}
	
	}
	
	
	int main()
	{
    int opcao =0;	//definindo a variaveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("#### Cart�rio da EBAC ####\n\n");
		printf("escolha a sua op��o no menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - sair do cartorio EBAC! \n\n");
		printf("op��o: ");  //fim do menu

		scanf("%d", &opcao); //armazenando escolha do usuario
	
		system("cls"); // responsavel por limpar a tela 
		
		switch (opcao) // inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun�oes 
			break;
			
			case 2:
			consulta(); //chamada de fun�oes
			break;
			
			case 3:
			deletar(); //chamada de fun�oes
			break;
			
			case 4: 
			printf("obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("essa op��o n�o esta disponivel !\n"); // fim da sele��o
			system("pause");
			break;
		}

		

	}
}
