#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void vazam(int n_sai, vector<int>& fila) {
    int sai;

    cin >> sai;

    for (int i = 0; i < fila.size(); i++) {
        if (fila[i] == sai) {
            fila.erase(fila.begin() + i);
        }
    }
}

void showme(vector<int>& vet) {
    cout << "[ ";
    for (int i = 0; i < vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << "]\n";;
}

int main() {
    vector<int> fila;
    int tam, pessoas, sain, sai;

    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cin >> pessoas;
        fila.push_back(pessoas);
    }

    cin >> sain;

    for (int i = 0; i < sain; i++) {
        vazam(sain, fila);
    }

    showme(fila);

}