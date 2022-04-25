#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*Map - Manipulação : 3 funções
sozinhos : Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)*/
vector<int> sozinhos(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    for(int i = 0; i < fila.size(); i++){ 
        if(fila[i] == fila[i+1]){ // se o valor for positivo e for igual ao próximo mais um
            novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
        }
    }
    return novaFila; // retornando o novo vetor
}

// mais_ocorrencias: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
int maisOcorrencias(const vector<int>& fila){
    int maior = 0; // criando uma variável para armazenar o maior valor
    int contador = 0; // criando uma variável para armazenar o contador
    for(int i = 0; i < fila.size(); i++){ // percorrendo o vetor
        if(fila[i] == fila[i+1]){ // se o valor for positivo e for igual ao próximo mais um
            contador++; // incrementando o contador
        }
        else{ // se não for igual
            if(contador > maior){ // se o contador for maior que o maior
                maior = contador; // atribuindo o contador ao maior
            }
            contador = 0; // zerando o contador
        }
    }
    return maior; // retornando o maior
}

// mais_recorrentes: Quais os níveis de stress mais recorrentes. (abs)
vector<int> maisRecorrentes(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    int maior = 0; // criando uma variável para armazenar o maior valor
    int contador = 0; // criando uma variável para armazenar o contador
    for(int i = 0; i < fila.size(); i++){ // percorrendo o vetor
        if(fila[i] == fila[i+1]){ // se o valor for positivo e for igual ao próximo mais um
            contador++; // incrementando o contador
        }
        else{ // se não for igual
            if(contador > maior){ // se o contador for maior que o maior
                maior = contador; // atribuindo o contador ao maior
            }
            contador = 0; // zerando o contador
        }
    }
    for(int i = 0; i < fila.size(); i++){ // percorrendo o vetor
        if(fila[i] == fila[i+1]){ // se o valor for positivo e for igual ao próximo mais um
            if(contador == maior){ // se o contador for igual ao maior
                novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
            }
        }
    }
    return novaFila; // retornando o novo vetor
}

