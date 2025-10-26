#include <stdio.h>
int main() {
 
  //Cartas  
  char estado[50];
  char codigo;
  char cidade[50];
  int populacao;
  float area;
  float pib;
  int pontosTuristicos;

  // Área para entrada de dados
    //Carta 1 - Campinas 
  char estado1[]="São Paulo";
  char codigo1 = 'C';
  char cidade1[] = "Campinas";
  int populacao1=1139047;
  float area1 = 795.7;
  float pib1 = 72.9;
  int pontos1 = 20;

  //Carta 2 - Curitiba
  char estado2[]="Paraná";
  char codigo2='P';
  char cidade2[] = "Curitiba";
  int populacao2 = 1800000;
  float area2 = 432.2;
  float pib2 = 98.0;
  int pontos2=30; 

  // Área para exibição dos dados da cidade
  printf("----Carta1 ----\n");
  printf("Estado: %s\n", estado1);
  printf("Código da carta: %n", cidade1);
  printf("Cidade: %s\n",cidade1);
  printf("População:%d habitantes\n",populacao1);
  printf("Área:%.1f km²\n", area1);
  printf("PIB:%.1f bilhões\n", pib1);
  printf("Número de pontos turísticos:%d\n", pontos1);

  printf("----Carta 2----\n");
  printf("Estado:%s\n", estado2);
  printf("Código da carta:%c\n", cidade2);
  printf("Cidade:%s\n",cidade2);
  printf("População:%d habitantes\n", populacao2);
  printf("Área: %.1f km²\n", area2);
  printf("PIB:%.1f bilhões\n", pib2);
  printf("Número de pontos turísticos:%d\n",pontos2);
 


return 0;
} 
