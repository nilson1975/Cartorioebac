#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s" , cpf); //%s refere-se o string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s" ,nome); //%s refere-se o string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa escrever
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); // %s refere-se o string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa escrever e o "a" significa escrever
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquvio
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,","); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s" ,cargo); // %s refere-se o string
	
	file = fopen(arquivo, "a" ); // cria o arquivo e o "a" significa escrever e o "a" significa escrever
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause");
	
}

int consulta() //Função responsável por consular usuários no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	printf("Digite o CPF a ser consultado: "); //consultando informação do usuário.
	scanf("%s",cpf); //%s refere-se o string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo e o "r" significa escrever
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("nEssas são as informações do usuário: "); //informação do usuário.
		printf("%s" , conteudo);
		printf("\n\n"); 
	}
	
	system("pause");
	
	
}

int deletar() //Função responsável por deletar usuários no sistema
{
	//inicio criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	printf("Digite o CPF do usuário a ser deletado: "); //deletando informação do usuário.
	scanf("%s",cpf); //%s refere-se o string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do Sistema\n\n");
	printf("opção: ");//Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls"); //responsável por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro(); //chamada de funções
		break;
		
		case 2:
		consulta(); //chamada de funçoes
		break;
		
		case 3:
		deletar(); //chamada de funçoes
		break;
		
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
		default: 
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;	
	}//fim da seleção
	
	

		}
 
}
