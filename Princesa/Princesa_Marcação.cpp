#include <iostream>
#include <vector>


using namespace std;

/* No problema, N pessoas se colocam numa fila circular e assumem valores de 1 até N.
Um número E é escolhido para iniciar o jogo. 
E pega a espada, mata o elemento à sua frente e passa a espada uma posição à frente. 
O jogo continua até que um único elemento permaneça vivo.
*/

void show(vector<int> vet, int sword){
    for(int i = 0; i < vet.size(); i++){
        cout << vet[i] << (i == sword ? " > " : " ");
    }
}

int acharVivo(vector<int> fila, int x){// andar pra frente dando um looping
    do{
        x = (x + 1) % fila.size();// precisa garantir q ele vai voltar 
    } while (fila[x] == false);  
    return x;
}

int main()
{ 
    int size{}, sword{};
    cin >> size >> sword;
    vector<int> fila(size, true);// vetor do tamanho size, com todos sendo verdade, todos vivos 
    sword -= 1;
   
   int qtd = fila.size() - 1;
   while(qtd--){
       sword = acharVivo(fila, sword);
       fila[sword] = false;
       sword = acharVivo(fila, sword);
   }

}