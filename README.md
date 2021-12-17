# Editor-de-PGM
Editor de pgm em c++

Documentação do progama de edição PGM 

Documentação referente ao programa final a partir da linha 66

Elaboração do algorítmo a partir das orientações em aula.
-------------------------------------------------------------

Um unico vetor, em ordem, com toda a matriz imagem.

 - Variáveis -
x - número de linhas
y - número de colunas
i - posiçao atual do vetor, um "ponteiro" do nosso progama.
aux - tamanho da matriz

____________________________
 - Imagem Negativa -
 Pega cada elemento em ordem, e subtrai do valor máximo de tons (res), o
valor do pixel atual (line). EX: 255-8 = 247

_____________________________
 - Espelho V -
 Apenas passa a matriz ao contrário, de traz pra frente.
 Um for com uma variável kont que recebe o tamanho da matriz, vai decrementando
e indicando os valores de traz pra frente a serem inscritos.

_____________________________
 - Espelho H -
 Um for, que anda linha por linha (representado por kontx), com outro for que escreve a
linha ao contrário (konty).
 Kontx recebe o zero, e vai incrementando, e konty recebe o numero de linhas, e vai
decrementando, possibilitando que a linha seja escrita de traz pra frente.

_____________________________
 - Girar 90 Anti H -
 Insere o último elemento de cada uma das linhas, depois o penúltimo e assim por diante
 Em um for, pega o tamanho da linha (kontx), e vai decrementando até chegar em zero, e dentro
disso, vai pulando de linha em linha até o final do arquivo. (konty)
 1 2   3   4  5
 6 7   8   9  10      x = 5; y = 3
11 12 13  14  15
                                  
5  10  15            5 + (0 * 5) = 5 
4   9  14            5 + (1 * 5) = 10
3   8  13            5 + (2 * 5) = 15
2   7  12            4 + (0 * 5) = 4
1   6  11            4 + (1 * 5) = 9     (...)
_____________________________


versão 8; le a mãe somente uma vez.
  
 1 2   3   4  5
 6 7   8   9  10      x = 5; y = 3
11 12 13  14  15

11  6  1 
12  7  2
13  8  3
13  9  4
15  10  5

aux2 = 11
aux1 = 11

--------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------

Versão Trabalho AEDS II - Ponteiros, manipulação de imagem, criação de 
funções e cabeçalho
Alunos:

André Augustho Sarti Trindade Silva - 2021.1.08.001
Augusto Vieira de Oliveira - 2021.1.08.002
Diego de Magalhães Vieira - 2021.1.08.004

--------------------------------------------------------------------------------------
Notas de atualização:


Atualização 17/12/2021 - Para usuários Netbeans

Execução no Netbeans comprometida por duplicidade de declaração. 
A solução da versão anterior se torna um problema quando executada no netbeans.
Para execução no netbeans se faz necessária a exclusão da linha declarada no 
arquivo funcImg.h responsável por chamar o arquivo funcs.cc 

        #include <fstream>
---->>  #include "funcs.cc"  <<--- excluir linha 2 no arquivo funcImg.h
        using namespace std;

-- Vinheta

Implementação da função Vinheta (Escurecimento das bordas).

-- VS Code: memória destinada ao compilador. 
Gerenciar/
configurações/
Buscar: compiler/
-- Aqui nessa opção de flags inserir o código abaixo
--> C-cpp-complie-run:Cpp-glags

Código:
-Wl,--stack,41943040

Resultado:

-Wall -Wextra -Wl,--stack,41943040

Esse comando aumenta a memória disponível utilizada pelo compilador. 

-- Menu de opções para usuário. 

Adição do menu de seleção de opções. 

------------------------------------------------------------------------------------
atualização 16/12/2021 - Para usuários VS Code

Das versões anteriores resta apenas o algorítmo. 
Nesta versão foram introduzidos os ponteiros e todas as 
transformações de imagem. Além disso, os requisitos do trabalho
foram atendidos. 

--------------------------------------------------------------------------------------

Variáveis de controle:

int x, y, i, cont, res, newval
strings arq, nome, line

Variáveis situacionais: aux, aux1, aux2, aux3

arquivos: mae, filho, stanford.pgm

Ponteiros: *start, *fim, *aux1, *aux2

Bibliotecas:    #include <iostream>
                #include <fstream>

                #include "leitoaRoleteh.h" 

using namespace std;

Declaração de variáveis

Estrutura padrão - int main(void)

Abertura do arquivo mae - stanford.pgm
Leitura do cabeçalho
Criação do arquivo filho.

funções de modificação e criação do arquivo filho.

Arquivos gerados: 
stanford0.pgm, stanford1.pgm, stanford2.pgm,
stanford3.pgm, stanford4.pgm, stanford5.pgm.

Respectivamente: 
Inversão de cores (imagem negativa), Espelho Horizontal,
Espelho Vertical, Giro Anti horário, Giro Horário e vinheta.

----------------------------------------------------------------------------------
Criação das funções: -- funcs.cc --

void negativa(string arq, int res, int *start, int *fim, int *aux);
void espelhoV(string arq, int *start, int *fim, int*aux);
void espelhoH(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void g90anti_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void g90_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x);
void vinheta(string arq, int res, int *start, int *fim, int x, int y)

----------------------------------------------------------------------------------
Atribuição de cabeçalho: -- funcImg.h --

Problema de compatibilidade e declaração de funções/cabeçalho: 

No VSCode, apesar dos arquivos existirem nos diretórios corretos, o funcionamento
só ocorreu após o arquivo de funções ser invocado no arquivo header. 

Solução: 

Chamar o arquivo funcs.cc no header funcImg.h

        #include <fstream>
 *****  #include "funcs.cc" *****
        using namespace std;

---------------------------------------------------------------------------------
Atribuição de cabeçalho: -- funcImg.h --

Problema de compatibilidade e declaração de funções/cabeçalho: 

No Netbeans, faz-se necessária a exclusão da linha marcada por ****.

Solução: 

Excluir a chamada do arquivo funcs.cc no header funcImg.h

        #include <fstream>
 *****  #include "funcs.cc" *****
        using namespace std;

---------------------------------------------------------------------------------

Imagem Negativa --- arquivo funcs.cc; linha 7

função:

void negativa(string arq, int res, int *start, int *fim, int *aux1)

Descrição:

A partir do vetor gerado com as informções do arquivo mae é realizada
a transformação dos pixels. Cada posição recebe a resolução do arquivo
subtraida de seu próprio valor. Para tanto, faz-se uso da variável res e 
do ponteiro *aux1. Aqui a informção é reecrita. 

---------------------------------------------------------------------------------

Espelho Vertical --- arquivo funcs.cc; linha 15

função:

void espelhoV(string arq, int *start, int *fim, int*aux1)

Descrição:

A imagem é invertida verticalmente através da realocação dos pixels.

---------------------------------------------------------------------------------

Espleho Horizontal --- arquivo funcs.cc; linha 23

função:

void espelhoH(string arq, int *start, int *fim, int *aux1, int *aux2, int x)

Descrição: 

A imagem é invertida horizontalmente através da realoção dos pixels. 
O valor dos pixels mudam de posição. 

---------------------------------------------------------------------------------

Girar 90 graus no sentido anti Horário --- arquivo funcs.cc; linha 33

função:

void g90anti_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x)

Descrição: 

A imagem recebe o efeito de rotação no sentido anti horário. Isso irá alterar as 
variáveis de controle x, y que serão invertidas caso a imagem seja retangular. 
Os valores mudam de posição. 

---------------------------------------------------------------------------------

Girar 90 graus no sentido horário --- arquivo funcs.cc; linha 45

função:

void g90_H(string arq, int *start, int *fim, int *aux1, int *aux2, int x)

Descrição:

A imagem recebe o efeito de rotação no sentido horário. Isso irá alterar as 
variáveis de controle x, y que serão invertidas caso a imagem seja retangular. 
Os valores mudam de posição.

---------------------------------------------------------------------------------

Vinheta --- arquivo funcs.cc; linha 62

função: 

void vinheta(string arq, int res, int *start, int *fim, int x, int y)

Descrição:

Escurecimento gradual das bordas da imagem. A função altera os valores 
das bordas para o centro com concentração decrescente. A região mais 
externa fica mais escura e o centro da imagem permanece inalterado. 
----------------------------------------------------------------------------------
  
 
