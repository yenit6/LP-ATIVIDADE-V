#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 3

struct recursos // nome autoexplicativo
{
  char nome[200];
  char cargo[200];
  float salario;
  char matricula[200];
};

float beneficioFGTS(float salario)
{
  float resultado;
  float fgts;
  resultado = salario * 0.08;

  return resultado;
}

float beneficioINSS(float salario)
{
  float resultade;
  float INSS;
  resultade = salario * 0.2;

  return resultade;
}

int main()
{

  struct recursos a[m];
  int i;
  int opcao, op;
  char qualificacao[2000];
  float fgts;
  int trabalho;
  float inss;

  printf("registre o funcionario:\n");

  printf("digite o nome: ");
  gets(a[i].nome);

  printf("digite o numero de matricula: ");
  gets(a[i].matricula);

  printf("digite o cargo: ");
  gets(a[i].cargo);

  printf("digite quantos anos de trabalho: ");
  scanf("%d", &trabalho);

  printf("digite o salario do funcionario: ");
  scanf("%f", &a[i].salario);

  printf("\n");

  do
  {
    printf("\nMenu:\n");

    printf("1 - Consultar funcionario registrado\n");
    printf("2 - calcular beneficio do funcionario\n");
    printf("3 - condicoes de aposentadoria \n");
    printf("4 - tipo de vaga \n");
    printf("5- sair do programa\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao)
    {

    case 1:
      printf("Nome: %s\n", a[i].nome);
      printf("matricula: %s\n", a[i].matricula);
      printf("cargo: %s\n", a[i].cargo);
      printf("salario: %.1f\n", a[i].salario);
      break;

    case 2:

      fgts = beneficioFGTS(a[i].salario);
      printf("fgts: R$ %.1f\n", fgts);

      inss = beneficioINSS(a[i].salario);
      printf("inss: R$ %.1f\n", inss);

      break;
    case 3:

      printf("tempo de trabaho: %d\n", trabalho);

      if (trabalho >= 30)
      {
        printf("sujeito a aposentadoria\n");
      }
      else
      {
        printf("nao e sujeito a aposentadoria\n");
      }

      break;

    case 4:

      printf("qual o tipo de vaga:\n");
      printf("1- estagiario.\n 2- jovem aprendiz.\n3- efetivo: ");
      scanf("%d", &op);

      printf("\n");

      if (op = 1)
      {
        printf("estagiario");
      }
      else if (op = 2)
      {
        printf("jovem aprendiz");
      }
      else
      {
        printf("efetivo");
      }
      printf("\n");

      break;

    case 5:
      printf("fechando programa.\n");
      break;

    default:
      printf("Opcao invalida. Tente novamente.\n");
    }

  } while (opcao != 5);

  return 0;
}
