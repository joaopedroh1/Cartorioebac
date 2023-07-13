#include <stdio.h> //biblioteca de comunicação pelo usuaria
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro () // função responsavel por cadastrar os usuarios no sistema 
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser adastrado: "); //coletando informações do usuario
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
		printf("Não foi possivel abrir o aquivo, Não localizado...!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
		printf("O cpf não se encontra no nosso sitema! .\n");
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
	
		printf("#### Cartório da EBAC ####\n\n");
		printf("escolha a sua opção no menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - sair do cartorio EBAC! \n\n");
		printf("opção: ");  //fim do menu

		scanf("%d", &opcao); //armazenando escolha do usuario
	
		system("cls"); // responsavel por limpar a tela 
		
		switch (opcao) // inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funçoes 
			break;
			
			case 2:
			consulta(); //chamada de funçoes
			break;
			
			case 3:
			deletar(); //chamada de funçoes
			break;
			
			case 4: 
			printf("obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("essa opção não esta disponivel !\n"); // fim da seleção
			system("pause");
			break;
		}

		

	}
}
