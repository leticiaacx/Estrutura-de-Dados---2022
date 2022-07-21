#include <iostream>
#include <vector>

using namespace std;

void showme(vector<int> vet){ // vai mostrar o q tem dentro
    for (auto i : vet)
        cout << i << ' ';
}

struct Pos{
    int linha;
    int coluna;
    Pos(int linha, int coluna) : linha(linha), coluna(coluna) {};

};

// retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.linha, p.coluna - 1}, {p.linha - 1, p.coluna}, {p.linha, p.coluna + 1}, {p.linha + 1, p.coluna} };
}

bool walk(vector<string> &mat, Pos inicio, Pos fim)// 
{
    if (inicio.linha == fim.linha && inicio.coluna == fim.coluna)
    {
        mat[inicio.linha][inicio.coluna] = '.';
        return true;
    }

    if (mat[inicio.linha][inicio.coluna] != '_')
        return false;

    mat[inicio.linha][inicio.coluna] = '.';

    mat[inicio.linha][inicio.coluna] = 'e';
    return false;
}

void wrong(vector<string> &mat)
{
    int nl = mat.size();
    int nc = mat[0].size();
    for (int l = 0; l < nl; l++)
        for (int c = 0; c < nc; c++)
            if (mat[l][c] == 'e')
                mat[l][c] = '_';
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> labirinto(nl, "");
    getchar();
    Pos inicio, fim;

    for (int i = 0; i < nl; i++){
        getline(cin, mat[i]);

    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (mat[l][c] == 'I')
            {
                mat[l][c] = '_';
                inicio = Pos{l, c};
            }
            if (mat[l][c] == 'F')
            {
                mat[l][c] = '_';
                fim = Pos{l, c};
            }
        }
    }

    walk(mat, inicio, fim);
    wrong(mat);

    for (string line : mat){
        cout << line << endl;
    }
  }

}