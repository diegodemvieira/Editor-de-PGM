#include <fstream>
#include <iostream>

using namespace std;


void negativa(string arq, int res, int *start, int *fim, int *aux1){
   ofstream filho;
   filho.open(arq, ios::app);
   for(aux1 = start; aux1< fim; aux1++){
      filho << res - *aux1 << " ";
   }
   filho.close();
}

void espelhoV(string arq, int *start, int *fim, int*aux1){
   ofstream filho;
   filho.open(arq, ios::app);
   for(aux1 = fim-1; aux1 > start; aux1--){
      filho << *aux1 << " ";
   }
   filho.close();
}

void espelhoH(string arq, int *start, int *fim, int *aux1, int *aux2, int x){
   ofstream filho;
   filho.open(arq, ios::app);
   for(aux2 = start + x - 1; aux2 <= fim; aux2 += x){
      for(aux1 = aux2; aux1 > aux2 - x; aux1--){
         filho << *aux1 << " ";
      }
   }
   filho.close();
}

void g90anti_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x){
   ofstream filho;
   filho.open(arq, ios::app);
   int *aux3;
   aux3 = fim;
   for(aux2 = start + x -1; aux2 >= start; aux2--, aux3 --){
      for(aux1 = aux2; aux1 <= aux3 ; aux1 += x){
         filho << *aux1 << " ";
      }
   }
   filho.close();
}

void g90_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x){
   ofstream filho;
   filho.open(arq, ios::app);
   int *aux3;
   aux3 = start;
   for(aux2 = fim - x; aux2 < fim; aux2++, aux3++){
      for(aux1 = aux2; aux1 >= aux3; aux1 -= x){
         filho << *aux1 << " ";
      }
   }
   filho.close();
} 

void vinheta(string arq, int res, int *start, int *fim, int x, int y){
   ofstream filho;
   filho.open(arq, ios::app);
   int *aux3, *auxStart, *auxEnd, *q1, *q2, *q3, *q4, *aux_vetor;
   int valorEscurecer;
   int vetor_aux[x * y];
   auxStart = &vetor_aux[0];
   auxEnd = &vetor_aux[x*y];
   q1 = &vetor_aux[0];
   q2 = &vetor_aux[x];
   q3 = &vetor_aux[(x*y) - x];
   q4 = &vetor_aux[x*y];
 
   for(aux3 = start, aux_vetor = auxStart; aux3 < fim; aux3++, aux_vetor++){  //copia vetor
      *aux_vetor = *aux3;
   }
   for(int cont = (y/15); cont != 0; cont--){  
      valorEscurecer = (res/20) * cont;

      for(aux_vetor = q1; aux_vetor < q2; aux_vetor++){ //cima
         *aux_vetor -= valorEscurecer;
         if(*aux_vetor < 0){
            *aux_vetor = 0;
         }
      }
      for(aux_vetor = q2; aux_vetor < q4; aux_vetor += x){  //direita v
         *aux_vetor -= valorEscurecer;
         if(*aux_vetor < 0){
            *aux_vetor = 0;
         }
      }
      for(aux_vetor = q4 - 1; aux_vetor > q3; aux_vetor--){ //baixo v
         *aux_vetor -= valorEscurecer;
         if(*aux_vetor < 0){
            *aux_vetor = 0;
         }
      } 
      for(aux_vetor = q3; aux_vetor > q1; aux_vetor -= x){   //esquerda
         *aux_vetor -= valorEscurecer;
            if(*aux_vetor < 0){
               *aux_vetor = 0;
            }
      } 
      q1 = q1 + x + 1;
      q2 = (q2 + x) - 1;
      q3 = (q3 - x) + 1; 
      q4 =  q4 - x - 1;
   }  

   for(aux_vetor = auxStart; aux_vetor < auxEnd; aux_vetor++){    //imprime
      filho << *aux_vetor << " ";
   }     
}
void escurecer(string arq, int *start, int *fim, int *aux1, int res){
   ofstream filho;
   filho.open(arq, ios::app);
   for(aux1 = start; aux1< fim; aux1++){
      *aux1 -= (res/5);
      if(*aux1 < 0){
         *aux1 = 0;
      }
      filho << *aux1 << " ";
   }
   filho.close();
}

void menu(){
   cout << "-- Escolha uma opcao para executar: --\n";
   cout << "1 . Imagem Negativa\n";
   cout << "2 . Espelho Horizontal\n";
   cout << "3 . Espelho Vertical\n";
   cout << "4 . Girar no sentido Anti-Horario\n";
   cout << "5 . Girar no sentido Horario\n";
   cout << "6 . Escurecer Bordas\n";
   cout << "7 . Escurecer 20% toda a Imagem\n";
   cout << "Insira 0 para finalizar o programa\n";
   cout << "--------------------------------------\n";
}

void cabecalho(string arq, int res, int x, int y, int cont){
   ofstream filho;
   filho.open(arq);
   filho << "P2\n";
   cout << cont << "- ";
   if(cont == 4 || cont == 5){
      filho << y << " ";
      filho << x << "\n"; 
   }
   else{
      filho <<  x << " ";
      filho << y << "\n"; 
   }
   filho << res << "\n";
}
