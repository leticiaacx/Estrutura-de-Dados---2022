#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

// Filter - Operações de Filtragem: 4 funções
// clonar : retorna um novo vetor copiando os valores do vetor de entrada
vector<int> clonar(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    for(int i = 0; i < fila.size(); i++){ 
        novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
    }
    return novaFila; // retornando o novo vetor
    
}

// pegar_homens: retorne uma lista com os homens (valores positivos)
vector<int> pegarHomens(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    for(int i = 0; i < fila.size(); i++){ 
        if(fila[i] > 0){ // se o valor for positivo
            novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
        }
    }
    return novaFila; // retornando o novo vetor
}

// pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
vector<int> pegarCalmos(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    for(int i = 0; i < fila.size(); i++){ 
        if(fila[i] < 10){ // se o valor for positivo
            novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
        }
    }
    return novaFila; // retornando o novo vetor
}

// pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)
vector<int> pegarMulheresCalmas(const vector<int>& fila){
    vector<int> novaFila; // criando um novo vetor
    for(int i = 0; i < fila.size(); i++){ 
        if(fila[i] < 0 && fila[i] > -10){ // se o valor for positivo
            novaFila.push_back(fila[i]); // colocando os valores do vetor de entrada no novo vetor
        }
    }
    return novaFila; // retornando o novo vetor
}

// Acesso: 5 funções
// inverter_com_copia
vector<int> inverterCCopia(const vector<int>& fila){
    vector<int> novaFila = clonar(fila); // criando um novo vetor
    int tam = novaFila.size(); // pegando o tamanho do vetor
    for(int i = 0; i < tam/2; i++){ // fazendo a troca de posições
        int aux = novaFila[i];
        novaFila[i] = novaFila[tam-i-1];
        novaFila[tam-i-1] = aux;
    }
    return novaFila; // retornando o novo vetor
}

// inverter_inplace
void inverterIP(vector<int>& fila){
    int tam = fila.size(); // pegando o tamanho do vetor
    for(int i = 0; i < tam/2; i++){ // fazendo a troca de posições
        int aux = fila[i];
        fila[i] = fila[tam-i-1];
        fila[tam-i-1] = aux;
    }
}

// sortear
void sortear(vector<int>& fila){
    int tam = fila.size(); // pegando o tamanho do vetor
    for(int i = 0; i < tam; i++){ // fazendo a troca de posições
        int aux = fila[i];
        int j = rand() % tam;
        fila[i] = fila[j];
        fila[j] = aux;
    }
}

// embaralhar
void embaralhar(vector<int> &vet){
    for (int i = 0; i < vet.size(); i++){
        int r = rand() % vet.size();

        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
}

// ordena o vetor original
void ordenar(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        for (int x = i; x < v.size(); x++){
            if (v[i] > v[x]){
                int aux = v[i];
                v[i] = v[x];
                v[x] = aux;
            }
        }
    }
}

/*Conjuntos: 3 funções
exclusivos: O fiscal permitiu a entrada de um único representante de cada valor, ou seja,
uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?*/
vector<int> exclusivos(const vector<int> &v){
    vector<int> repetido;
    bool flag; // se eu encontro ou não um numero igual, num indice antes ou depois de i
    for (int i = 0; i < v.size(); i++){
        flag = false; // ate o momento eu nao encontro o elemento q esta repetido a esquerda ou direita
        for (int j = 0; j < i; j++){
            if (v[i] == v[j]){
                flag = true; // encontrei igual
                break;
            }
        }
        if (flag == false){
            repetido.push_back(v[i]);
        }
    }
    return repetido;
}

//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4}
vector<int> diferentes(const vector<int> &v){
    vector<int> rep{};
    bool flag = false;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < rep.size(); j++){
            if (v[i] == rep[j] || v[i] * -1 == rep[j]){
                flag = true;
                break;
            }
        }
        if (flag == true){
            flag = false;
            continue;
        }
        else{
            if (v[i] < 0){
                rep.push_back(v[i] * -1);
            }
            else{
                rep.push_back(v[i]);
            }
        }
    }
    return rep;
}

//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
vector<int> abandonados(const vector<int> &v){
    vector<int> v2{};
    vector<int> v3{};
    bool flag = false;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v2.size(); j++){
            if (v[i] == v2[j]){
                flag = true;
                v3.push_back(v[i]);
                break;
            }
        }
        if (flag == true){
            flag = false;
            continue;
        }
        else{
            v2.push_back(v[i]);
        }
    }
    return v3;
}
