#include <iostream>
#include <fstream>
#include "funcImg.h"

using namespace std;
int x, y, cont, res, i, *start, *fim, *aux1, *aux2;


int main(void){

   string arq;
   string line;
   ifstream mae ("stanford_Vinheta.pgm");
   ofstream filho;

   if(mae.is_open() ){
      getline( mae, line);   // Joga a primeira linha P2 fora
      mae >> x;              // Tamanho matriz = x
      mae >> y;              // Tamanho matriz = y
      mae >> line;           // Resoluçao matriz
      res = stoi(line);
   }
   int vetor[x * y];   // Salva o tamanho padrão da matriz
   start = &vetor[0];  // Ponteiro para o inicio
   fim = &vetor[x*y];  // Ponteiro para o fim
   i = 0;

   while( !mae.eof() ){
      mae >> line;
      vetor[i] = stoi(line);  // Preenche o Vetor
      i++;
   }
   mae.close();

   cout << "\n-------- Editor de Imagem PGM --------\n";
   cout << "- Bem-vindo ao editor de imagens PGM -\n\n";
   
   do{
      menu();
      cin >> cont;
      while(cont > 7 || cont < 0){
         cout << "Opcao invalida, digite novamente.";
         cout << "\n---------------------------------------\n";
         cin >> cont;
      }
      // IMAGEM NEGATIVA
      if(cont == 1){
         cout << "Gerando imagem Negativa\n";
         arq = "stanford_Negativa.pgm";
         cabecalho(arq, res, x, y, cont);
         negativa(arq, res, start, fim, aux1);
      }

      // ESPELHO H
      if(cont == 2){
         cout << "Gerando imagem Espelho H\n";
         arq = "stanford_EspelhoH.pgm";
         cabecalho(arq, res, x, y, cont);
         espelhoH(arq, start, fim, aux1, aux2, x);
      }

      // ESPELHO V
      if(cont == 3){
         cout << "Gerando imagem Espelho V\n";
         arq = "stanford_EspelhoV.pgm";
         cabecalho(arq, res, x, y, cont);
         espelhoV(arq, start, fim, aux1);
      }

      // GIRAR 90 GRAUS ANTI-H
      if(cont == 4){
         cout << "Gerando imagem girada Anti-H\n";
         arq = "stanford_AntiH.pgm";
         cabecalho(arq, res, x, y, cont);
         g90anti_H(arq, start, fim, aux1, aux2, x);
      }

      // GIRAR 90 GRAUS HORÁRIO
      if(cont == 5){
         cout << "Gerando imagem girada H\n";
         arq = "stanford_Horario.pgm";
         cabecalho(arq, res, x, y, cont);
         g90_H(arq, start, fim, aux1, aux2, x);
      }

      // VINHETA
      if(cont == 6){
        cout << "Gerando imagem Vinheta\n";
         arq = "stanford_Vinheta.pgm";
         cabecalho(arq, res, x, y, cont);
         vinheta(arq, res, start, fim, x, y);
      } 

      // ESCURECER 20%
      if(cont == 7){
        cout << "Gerando imagem Escura\n";
         arq = "stanford_Escuro.pgm";
         cabecalho(arq, res, x, y, cont);
         escurecer(arq, start, fim, aux1, res);
      } 

   } while(cont != 0);

   cout << "Progama Finalizado, ate mais!\n\n";

  return 0;
}
