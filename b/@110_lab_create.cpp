#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pos {
    int l, c;
    Pos (int l, int c): l(l), c(c) {};
};

void showme(std::vector<std::string> &mat){
    for (auto element : mat){
        std::cout << element << std::endl;
    }
}

vector<Pos> getV(Pos p) {
    auto [l, c] = p;
    return {{l, c -1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

bool furar(vector<std::string> &lab, Pos& pos)
{
    int count = 0;
    auto aux = getV(pos);

    if (lab[pos.linha][pos.coluna] == ' '){
        return false;
    }

    for (auto [l, c] : aux){
        if (l >= int(lab.size()) || c >= int(lab[0].size()) || l < 0 || c < 0){
            continue;
        }

        if (lab[l][c] == '#'){
            count++;
        }
    }

    if (count >= 3){
        return true;
    } else{
        return false;
    }
}

void derrubarP(std::vector<std::string> &lab, Posicao &pos)
{
    int nl = lab.size();
    int nc = lab[0].size();
    auto l = pos.linha;
    auto c = pos.coluna;

    if (l >= nl - 1 || c >= nc - 1 || l < 1 || c < 1){
        return;
    }

    if (furar(lab, pos)){
        lab[l][c] = ' ';
        auto vizinhos = getV(pos);
        random_shuffle(vizinhos.begin(), vizinhos.end());

        for (auto vizinho : vizinhos){
            derrubarP(lab, vizinho);
        }
    }
}

Pos iniciar(vector<string> &lab){
    int l_pos = rand() % (lab.size() - 2) + 1;
    int c_pos = rand() % (lab[0].size() - 2) + 1;

    return {l_pos, c_pos};
}

int main(int argc, char *argv[])
{
    int nl{}, nc{};

    if (argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    vector<string> labirinto(nl, string(nc, '#'));

    auto inicio = iniciar(labirinto);

    derrubarP(labirinto, inicio);
    showme(labirinto);

    return 0;
}