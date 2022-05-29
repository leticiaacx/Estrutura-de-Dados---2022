#include <iostream>
#include <vector>
using namespace std;

/* Vamos preencher uma matriz aleatoriamente com árvores # e espaços vazios *
Leia do usuário utilizando os parâmetros de argc e argv a quantidade de linhas e quantidade de colunas
e a porcentagem de árvores.
Utilize a geração de números aleatórios para gerar sempre matrizes diferentes. 
Conte a quantidade de árvores que seu algoritmo está colocando e veja se se aproxima do que foi solicitado pelo usuário.
Uma forma simples de fazer isso é para cada célula fazer (rand() % 100 < porcentagem) 
para verificar se ela deve ser uma árvore */

void mostrar(vector<string> map)
{
    for (auto line : map)
    {
        cout << line << endl;
        cout << endl;
    }
}

int arvore(vector<string> map)
{
    int porcent = 0;

    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == '#'){
                map[i][j] = (rand () % 100 < porcent ? '#' : '*');
                return 0;
            } else if(map[i][j] == '*'){
                return 1;
            }
        }
    }
}

int main()
{

 vector<string> map;
 int nl { };

string line;
for(int i = 0; i < nl; i++){
    arvore(map);
    map.push_back(line);
}

arvore(map);
mostrar(map);

}