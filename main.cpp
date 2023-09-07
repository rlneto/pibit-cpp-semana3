#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
#include <array>
#include <vector>

using namespace std;

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(nullptr));

  cout << "Esse algoritmo gera um vetor de coordenadas x e y aleatórias variando entre -255 e 255 e encontra os cantos de um quadrado que engloba todas as coordenadas." << endl << endl;
  cout << "Pressione qualquer tecla para continuar..." << endl;
  cin.get();
  cout << "Gerando um vetor com 1000 coordenadas aleatórias..." << endl << endl;
  vector<array<int, 2>> views;
  for (int i = 0; i < 1000; i++)
  {
    array<int, 2> view;
    view[0] = rand() % 511 - 255;
    view[1] = rand() % 511 - 255;
    views.push_back(view);
  }
  cout << "Vetor gerado com sucesso!" << endl << endl;
  cout << "Primeiras 10 coordenadas do vetor gerado para demonstração:" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << "(" << views[i][0] << ", " << views[i][1] << ")" << endl;
  }
  cout << endl << "Pressione qualquer tecla para continuar..." << endl;
  cin.get();
  cout << endl << "Encontrando os cantos do quadrado que engloba todas as coordenadas..." << endl << endl;

  array<int, 2> canto_inf_esq {0, 0};
  array<int, 2> canto_sup_esq {0, 0};
  array<int, 2> canto_inf_dir {0, 0};
  array<int, 2> canto_sup_dir {0, 0};

  for (array<int, 2> view : views)
  {
    if (view[0] < canto_inf_esq[0] && view[1] < canto_inf_esq[1])
    {
      canto_inf_esq[0] = view[0];
      canto_inf_esq[1] = view[1];
    }
    if (view[0] < canto_inf_esq[0] && view[1] > canto_sup_esq[1])
    {
      canto_sup_esq[0] = view[0];
      canto_sup_esq[1] = view[1];
    }
    if (view[0] > canto_inf_esq[0] && view[1] < canto_inf_esq[1])
    {
      canto_inf_dir[0] = view[0];
      canto_inf_dir[1] = view[1];
    }
    if (view[0] > canto_inf_esq[0] && view[1] > canto_sup_esq[1])
    {
      canto_sup_dir[0] = view[0];
      canto_sup_dir[1] = view[1];
    }
  }
    cout << "Canto inferior esquerdo: " << "(" << canto_inf_esq[0] << ", " << canto_inf_esq[1] << ")" << endl;
    cout << "Canto superior esquerdo: " << "(" << canto_sup_esq[0] << ", " << canto_sup_esq[1] << ")" << endl;
    cout << "Canto inferior direito: " << "(" << canto_inf_dir[0] << ", " << canto_inf_dir[1] << ")" << endl;
    cout << "Canto superior direito: " << "(" << canto_sup_dir[0] << ", " << canto_sup_dir[1] << ")" << endl << endl;
    cout << "Pressione qualquer tecla para sair..." << endl;
    cin.get();
    
    return 0;
}
