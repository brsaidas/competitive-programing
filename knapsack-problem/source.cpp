#include <bits/stdc++.h>

using namespace std;

//Maximo de voluma para o problema
#define MAXVOLUME 15

//arrays com os valores do problema
int volume[6] = {8, 7, 1, 4, 5, 3};
int preco[6] = {400, 200, 50, 150, 170, 75};

/*
  Funcao que resolve o problema considerando um determinado intervalo [0 ... indice]
  e um determinado volumaAtual ( <= 15 )
*/
int resolve(int indice, int volumeAtual) {
  /*
    Caso o intervalo tenha chagado ao fim ou o limite de volume foi atingido
    nao podemos mais adicionar nada, entao a solucao e zero
  */
  if (indice == 6 || volumeAtual == MAXVOLUME) return 0;

  //Solucao imaginando que nao colocamos o produto nesse indice
  int solucao = resolve(indice + 1, volumeAtual);

  //Solucao imaginando que colocamos o produto nesse indice
  if (volumeAtual + volume[indice] <= MAXVOLUME) {
    solucao = max(solucao,
      resolve(indice + 1, volumeAtual + volume[indice]) + preco[indice]);
  }

  //Retorna a solucao para chamada recursiva
  return solucao;
}

int main() {
  //Chamada da funcao que resolve o problema
  cout << "Melhor solucao: " << resolve(0, 0) << '\n';
  return 0;
}
