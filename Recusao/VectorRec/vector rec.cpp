#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void mostrar(vector<int> vet) { // vai mostrar o q tem dentro
    for (auto i : vet)
        cout << i << ' ';
}

void inverter(vector<int> vet) { //invertendo a ordem 
    for (int i = (int)vet.size() - 1; i >= 0; i--)
        cout << vet[i] << ' ';
}

int soma(vector<int> vet){ // vai somar o i mais o vetor 
    int somar{};
    for (int i : vet){
        somar += i;
    }

    return somar;
}

int multiplica(vector<int> vet) { // multiplicar o i mais o vetor
    int multiplicar{1};
    for (int i : vet){
        multiplicar *= i;
    }

    return multiplicar;
}

int menorElement(vector<int> vet) {// vai pegar o menor elemento e retornar 
    int menor = vet[0]; // criando um menor q vai receber o vet = 0
    for (int i = 0; i < (int)vet.size(); i++){
        if (vet[i] < menor)
            menor = vet[i];
    }

    return menor;
}

vector<int> inverterAux(vector<int> &vet) {
    vector<int> aux(vet);
    reverse(aux.begin(), aux.end());
    mostrar(aux);
}

int main()
{
    cout << "Insira os numeros do vetor: " << endl;

    string linha;
    getline(cin, linha);
    stringstream ss(linha);
    vector<int> vet;

    int elem{};
    while (ss >> elem){
        vet.push_back(elem);
    }

    cout << "Vetor: [ ";
    mostrar(vet);
    cout << " ]" << endl;

    cout << "Vetor invertido: [ ";
    inverter(vet);
    cout << " ]" << endl;

    cout << "A soma do vetor: " << soma(vet) << endl;

    cout << "A multiplicacao do vetor: " << multiplica(vet) << endl;

    cout << "O menor elemento do vetor: : " << menorElement(vet) << endl;

    cout << "E o vetor invertido: [ ";
    inverterAux(vet);
    cout << " ]";
}