#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ANO_ATUAL 2024

struct Cadastro{
  char nome[50];
  char sexo;
  char cidade[20];
  char telefone[10];
  int dia,mes,ano;
  int idade;
};

typedef struct Cadastro Pessoa;

main(){
  int x, mes, achou, i, j, pos, tamanho, novotamanho;
  Pessoa *agenda, *aux;
  char escolha;
  system("clear");
  printf("Informe o numero de pessoas a serem colocadas na agenda: ");
  scanf("%i",&tamanho);
  getchar();
  agenda = malloc(tamanho*sizeof(Pessoa));
  for(x = 0; x < tamanho; x++){
    printf("\nDigite o nome da %iª pessoa: ", x+1);
    gets(agenda[x].nome);
    printf("Digite o sexo da %iª pessoa: ", x+1);
    scanf("%c", &agenda[x].sexo);
    getchar();
    while(agenda[x].sexo != 'm' && agenda[x].sexo != 'M' && agenda[x].sexo != 'f' && agenda[x].sexo != 'F'){
      printf("Sexo inválido, digite novamente o sexo da %iª pessoa: ", x+1);
      scanf("%c", &agenda[x].sexo);
      getchar();
    }
    printf("Digite a cidade da %iª pessoa: ", x+1);
    gets(agenda[x].cidade);
    printf("Digite o telefone da %iª pessoa: ", x+1);
    gets(agenda[x].telefone);
    printf("Digite a data de nascimento\n");
    printf("Dia: ", x+1);
    scanf("%d", &agenda[x].dia);
    getchar();
    while(agenda[x].dia < 1 || agenda[x].dia > 31){
      printf("Dia inválido, digite novamente: ", x+1);
      scanf("%d", &agenda[x].dia);
      getchar();
    }
    printf("Mês: ", x+1);
    scanf("%d", &agenda[x].mes);
    getchar();
    while(agenda[x].mes < 01 || agenda[x].mes > 12){
      printf("Mês inválido, digite novamente: ", x+1);
      scanf("%d", &agenda[x].mes);
      getchar();
    }
    printf("Ano: ", x+1);
    scanf("%i", &agenda[x].ano);
    getchar();
    agenda[x].idade = ANO_ATUAL - agenda[x].ano;
  }
  system("clear");
  do{
    printf("Escolha uma das opções: \n[B] - Para buscar por pessoas\n[L] - Para listar pessoas \n[E] - Para excluir pessoas\n[I] - Para inserir pessoas\n[A] - Alterar dados\n[S] - Para sair\n");
    scanf("%c", &escolha);
    getchar();
    switch(escolha){
      case 's':
      case 'S':{
        printf("\nFinalizando programa...");
        getchar();
      } 
      break;
      case 'L':
      case 'l':{
        system("clear");
        printf("Listando os contatos da agenda: \n\n");
        for(x = 0; x < tamanho; x++){
          printf("//-------------------------//\n");
          printf("Nome: %s\n",agenda[x].nome);
          printf("Sexo: %c\n",agenda[x].sexo);
          printf("Cidade: %s\n",agenda[x].cidade);
          printf("Telefone: %s\n",agenda[x].telefone);
          if(agenda[x].mes < 10){
            if(agenda[x].dia < 10){
              printf("Data de nascimento: 0%i/0%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
            }
            else{
              printf("Data de nascimento: %i/0%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
            }
          } else{
            if(agenda[x].dia < 10){
              printf("Data de nascimento: 0%i/%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
            }
            else{
              printf("Data de nascimento: %i/%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
            }
          }
          printf("Idade: %i\n",agenda[x].idade);
        }
        printf("//-------------------------//\n\n");
      } 
      break;
      case 'A':
      case 'a':{
        printf("\nDigite a posição absoluta da pessoa que deseja alterar uma informação: ");
        scanf("%i", &pos);
        getchar();
        if(pos >= tamanho){
          printf("\nPosição inválida");
          getchar();
          system("clear");
        } else{
          printf("\nEscolha que informação deseja alterar: \n[0] - Nome\n[1] - Sexo\n[2] - Cidade\n[3] - Telefone\n[4] - Dia do nascimento\n[5] - Mês do nascimento\n[6] - Ano do nascimento\n");
          scanf("%i", &x);
          getchar();
          printf("\n");
          switch(x){
            case 0:
              printf("Nome atual: %s\nNovo nome: ", agenda[pos].nome);
              gets(agenda[pos].nome);
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 1:
              printf("Sexo atual: %c\nNovo sexo: ", agenda[pos].sexo);
              scanf("%c", &agenda[pos].sexo);
              getchar();
              while(agenda[pos].sexo != 'm' && agenda[pos].sexo != 'M' && agenda[pos].sexo != 'f' && agenda[pos].sexo != 'F'){
                printf("Sexo inválido, digite novamente: ", x+1);
                scanf("%c", &agenda[pos].sexo);
                getchar();
              }
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 2:
              printf("Cidade atual: %s\nNova cidade: ", agenda[pos].cidade);
              gets(agenda[pos].cidade);
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 3:
              printf("Telefone atual: %s\nNovo telefone: ", agenda[pos].telefone);
              gets(agenda[pos].telefone);
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 4:
              printf("Dia do nascimento atual: %i\nNovo dia: ", agenda[pos].dia);
              scanf("%d", &agenda[pos].dia);
              getchar();
              while(agenda[pos].dia < 1 || agenda[pos].dia > 31){
                printf("Dia inválido, digite novamente: ", x+1);
                scanf("%d", &agenda[pos].dia);
                getchar();
              }
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 5:
              printf("Mês do nascimento atual: %i\nNovo mês: ", agenda[pos].mes);
              scanf("%d", &agenda[pos].mes);
              getchar();
              while(agenda[pos].mes < 01 || agenda[pos].mes > 12){
                printf("Mês inválido, digite novamente: ", x+1);
                scanf("%d", &agenda[pos].mes);
                getchar();
              }
              printf("\nAtualizado com sucesso");
              getchar();
              system("clear");
            break;
            case 6:
              printf("Ano do nascimento atual: %i\nNovo ano: ", agenda[pos].ano);
              scanf("%d", &agenda[pos].ano);
              getchar();
              printf("\nAtualizado com sucesso");
              getchar();
              agenda[pos].idade = ANO_ATUAL - agenda[pos].ano;
              system("clear");
            break;
          }
        }
      } 
      break;
      case 'I':
      case 'i':{
        tamanho++;
        agenda = realloc(agenda, tamanho * sizeof(Pessoa));
        i = tamanho - 1;
        printf("\nInforme o nome: ");
        gets(agenda[i].nome);
        printf("Informe o sexo: ");
        scanf("%c",&agenda[i].sexo);
        getchar();
        while(agenda[x].sexo != 'm' && agenda[x].sexo != 'M' && agenda[x].sexo != 'f' && agenda[x].sexo != 'F'){
          printf("\nSexo inválido, digite novamente: ", x+1);
          scanf("%c", &agenda[x].sexo);
          getchar();
        }
        printf("Informe a cidade: ");
        gets(agenda[i].cidade);
        printf("Informe o telefone: ");
        gets(agenda[i].telefone);
        printf("Informe sua data de nascimento: \n");
        printf("Dia: ");
        scanf("%d",&agenda[i].dia);
        getchar();
        while(agenda[x].dia < 1 || agenda[x].dia > 31){
          printf("Dia inválido, digite novamente: ", x+1);
          scanf("%d", &agenda[x].dia);
          getchar();
        }
        printf("\nMes: ");
        scanf("%d",&agenda[i].mes);
        getchar();
        while(agenda[x].mes < 01 || agenda[x].mes > 12){
          printf("Mês inválido, digite novamente: ", x+1);
          scanf("%d", &agenda[x].mes);
          getchar();
        }
        printf("\nAno: ");
        scanf("%i",&agenda[i].ano);
        getchar();
        agenda[i].idade=ANO_ATUAL - agenda[i].ano;
        system("clear");
      }
      break;
      case 'b':
      case 'B':{
        achou = 0;
        system("clear");
        printf("Digite o mês que deseja buscar por aniversariantes: ");
        scanf("%d", &mes);
        getchar();
        for(x = 0; x < tamanho; x++){
          if(mes == agenda[x].mes){
            printf("//-------------------------//\n");
            printf("Nome: %s\n", agenda[x].nome);
            printf("Sexo: %c\n", agenda[x].sexo);
            if(agenda[x].mes < 10){
              if(agenda[x].dia < 10){
                printf("Data de nascimento: 0%i/0%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
              }
              else{
                printf("Data de nascimento: %i/0%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
              }
            } else{
              if(agenda[x].dia < 10){
                printf("Data de nascimento: 0%i/%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
              }
              else{
                printf("Data de nascimento: %i/%i/%i\n", agenda[x].dia, agenda[x].mes, agenda[x].ano);
              }
            }
            printf("Idade: %i\n", agenda[x].idade);
            printf("Cidade: %s\n", agenda[x].cidade);
            printf("Telefone: %s\n", agenda[x].telefone);
            achou++;
          }
        }
        printf("//-------------------------//\n\n");
        printf("\n");
        if(achou == 0){
          printf("Nenhum aniversariante encontrado\n\n");
        }
      } 
      break;
      case 'E':
      case 'e':{
        printf("\nDigite a posicão (absoluta) que se deseja excluir um contato: ");
        scanf("%i",&pos);
        getchar();
        if(pos >= tamanho){
          printf("\nPosição inválida");
          getchar();
          system("clear");
        } else{
          aux = malloc((tamanho - 1)*sizeof(Pessoa));
          j=0;
          for (i=0; i< tamanho; i++){
            if (i != pos){
              strcpy(aux[j].nome, agenda[i].nome);
              aux[j].sexo = agenda[i].sexo;
              strcpy(aux[j].cidade, agenda[i].cidade);
              strcpy(aux[j].telefone, agenda[i].telefone);
              aux[j].dia = agenda[i].dia;
              aux[j].mes = agenda[i].mes;
              aux[j].ano = agenda[i].ano;
              aux[j].idade = agenda[i].idade;
              j++;
            }
          }
          free(agenda);
          agenda=aux;
          tamanho--;
          system("clear");
        }
      }
      break;
      default:
      printf("\nComando inválido\n");
      getchar();
    }
  }while(escolha != 's' && escolha != 'S');
}
