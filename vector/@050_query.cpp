#include <iostream>
#include <vector>

using namespace std;

vector<int> matchString(vector<string> consults, vector<string> busca) {
    int sizeb = busca.size();
    int sizec = consults.size();

    vector<int> vet;
    int count = 0;
    
    for (int i = 0; i < sizeb; i++) {
        for (int j = 0; j < sizec; j++) {
            if (busca[i] == consults[j]) {
                count++;
            }
        }
        vet.push_back(count); //add no final
        count = 0;
    }
    return vet; //retornando dps de add
}

int main(){
    int sizea {};
    int sizeb {};

    //preenchendo o vetor de consulta
    cin >> sizea;
    vector<string> consults(sizea, "");
    for(int i = 0; i < sizea; i++)
        cin >> consults[i];

    //preenchendo o vetor de busca
    cin >> sizeb;
    vector<string> busca(sizeb, "");
    for(int j = 0; j < sizeb; j++)
        cin >> busca[j];
    
    vector<int> vet = matchString(consults, busca);
    for(int i = 0; i < (int) vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << "\n";
    return 0;
}
