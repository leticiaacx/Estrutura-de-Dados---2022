#include <iostream>
#include <vector>

using namespace std;

bool inserir(string &line, int index, int value, int prox)
{
    for (int i = index + 1; i < index + 1 + prox; i++){
        if (i < line.size() && line[i] == value + '0')
            return false;
    }

    for (int i = index - prox; i < index; i++){
        if (i >= 0 && line[i] == value + '0')
            return false;
    }

    return true;
}

bool colocar(string &line, int index, int lim, int prox){
    if ((int)line.size() == index){
        cout << line << "<----\n";
        return true;
    }

    if (line[index] != '.'){//rec
        return colocar(line, index + 1, lim, prox);
    }

    for (int value = 0; value <= lim; value++){
        if (inserir(line, index, value, prox)){
            line[index] = value + '0';
            cout << line << '\n';
            if (colocar(line, index + 1, lim, prox)){ //rec
                return true;
            }
        }
    }

    line[index] = '.';
    cout << line << '\n';
    return false;
}

int main(){
    string line;
    int prox;
    cin >> line >> prox;

    int limite = 1;
    while (!colocar(line, 0, limite, prox)){
        limite++;
    }
}