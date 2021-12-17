#include <fstream>
#include "funcs.cc"
using namespace std;

#ifndef FUNCIMG_H
#define FUNCIMG_H

void negativa(string arq, int res, int *start, int *fim, int *aux);
void espelhoV(string arq, int *start, int *fim, int*aux);
void espelhoH(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void g90anti_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void g90_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void vinheta(string arq, int res, int *start, int *fim, int x, int y);
void escurecer(string arq, int *start, int *fim, int *aux1, int res);
void cabecalho(string arq, int res, int x, int y, int cont);
void menu();

#endif
