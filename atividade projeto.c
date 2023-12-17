#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 3

struct recursos
{
  char nome[m][200];
  char cargo[m][200];
  float salario[m];
  char matricula[m][200];
  int trabalho[m];
};

float beneficioFGTS(float salario)
{
  return salario * 0.08;
}

float beneficioINSS(float salario)
{
  return salario * 0.2;
}

void searchEmployeeBymatricula(struct recursos a, const char *searchmatricula)
{
  int found = 0;
  int i;

  for ( i = 0; i < m; i++)
  {
    if (strcmp(a.matricula[i], searchmatricula) == 0)
    {
      printf("Nome: %s\n", a.nome[i]);
      printf("Matrícula: %s\n", a.matricula[i]);
      printf("Cargo: %s\n", a.cargo[i]);
      printf("Salário: %.1f\n", a.salario[i]);
      
      return;
    }
  }

  if (!found)
  {
    printf("Funcionário com o nome '%s' não encontrado.\n", searchmatricula);
  }

 
}

int main()
{ 
    int i;
  struct recursos a;
  int opcao;
   char searchmatricula[200];

  for ( i = 0; i < m; i++)
  {
    printf("Registre o funcionário:\n");
    printf("Digite o nome: ");
    scanf("%s", a.nome[i]);

    printf("Digite o número de matrícula: ");
    scanf("%s", a.matricula[i]);

    printf("Digite o cargo: ");
    scanf("%s", a.cargo[i]);

    printf("Digite quantos anos de trabalho: ");
    scanf("%d", &a.trabalho[i]);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &a.salario[i]);
    printf("\n");
  }

  do
  {
    printf("\nMenu:\n");

    printf("1 - Consultar lista de colaboradores registrado\n");
    printf("2 - pesquisar  colaborador \n");
    printf("3 - Calcular benefícios dos funcionários\n");
    printf("4 - Condições de aposentadoria \n");
    printf("5 - Sair do programa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao)
    {
    case 1:
      for ( i = 0; i < m; i++)
      {
        printf("Nome: %s\n", a.nome[i]);
        printf("Matrícula: %s\n", a.matricula[i]);
        printf("Cargo: %s\n", a.cargo[i]);
        printf("Salário: %.1f\n", a.salario[i]);
      }
      break;

    case 3:
      for ( i = 0; i < m; i++)
      {
        float fgts = beneficioFGTS(a.salario[i]);
        printf("FGTS: R$ %.1f\n", fgts);

        float inss = beneficioINSS(a.salario[i]);
        printf("INSS: R$ %.1f\n", inss);
      }
      break;

    case 4:
      for ( i = 0; i < m; i++)
      {
        printf("Tempo de trabalho: %d\n", a.trabalho[i]);

        if (a.trabalho[i] >= 30)
        {
          printf("Sujeito a aposentadoria\n");
        }
        else
        {
          printf("Não é sujeito a aposentadoria\n");
        }
      }
      break;

    case 2:
    
       
      printf("Digite o matricula do funcionário a ser pesquisado: ");
      scanf("%s", searchmatricula);
      searchEmployeeBymatricula(a, searchmatricula);

      break;

    case 5:
      printf("Fechando programa.\n");
      break;

    default:
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (opcao != 5);

  return 0;
}