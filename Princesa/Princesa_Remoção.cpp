#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> vet, int sword)
{
    for (int i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << (i == sword ? " > " : " ");
    }
}

int acharVivo(vector<int> fila, int x)
{ // andar pra frente dando um looping
    do
    {
        x = (x + 1) % fila.size(); // precisa garantir q ele vai voltar
    } while (fila[x] == false);
    return x;
}

int main(){
    int size{}, sword;
    cin >> size >> sword;
    vector<int> vet(size, true);

    sword = -1;
    int qtd = vet.size() - 1;
    while(qtd--){
        sword = (sword + 1) % vet.size();
        vet.erase(vet.begin() + sword);
        sword = sword % vet.size();
    }


}