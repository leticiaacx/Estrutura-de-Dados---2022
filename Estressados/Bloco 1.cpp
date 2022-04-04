#include <iostream>
#include <vector>

using namespace std;

// bloco 1 -  Buscar ------------------------------------------
// existe: Alguém com o valor X está na fila?
bool existe(vector<int> fila, int x){
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] == x)// toda vida que o i for igual a x, vai retornar true
            return true;
    }
    return false;// caso não encontre o valor x, retorna false

}

//contar: Quantas vezes o valor X apareceu na fila?
int contar(vector<int> fila, int x){
    int cont = 0;
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] == x)
            cont++; // toda vida que o i na fila for igual a x, conta mais um
    }
    return cont; // retorna o contador
}

// procurar: Em que posição da fila aparece X pela primeira vez?
int procurar(vector<int> fila, int x){
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] == x)
            return i; // toda vida que o i na fila for igual a x, retorna o i
    }
    return -1; // caso não encontre o valor x, retorna -1
}

// procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
int procurarApartir(vector<int> fila, int x, int pos){ // pos = posição inicial
    for(int i = pos; i < fila.size(); i++){// i começa na posição inicial
        if(fila[i] == x)
            return i; // toda vida que o i na fila for igual a x, retorna o i
    }
    return -1; // caso não encontre o valor x, retorna -1
}

// Melhor caso -----------------------------------------------------------
// procurar_menor: qual o menor valor da lista?
int procurarMenor(vector<int> fila){
    int menor = fila[0]; // menor recebe o primeiro valor da fila
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] < menor)// toda vida que o i for menor que o menor, o menor recebe o i
            menor = fila[i];
    }
    return menor;// retorna o menor
}

// procurar_pos_menor : qual a posição do menor valor da lista ?
int procurarPosMenor(vector<int> fila){
    int menor = fila[0]; // menor recebe o primeiro valor da fila
    int pos = 0; // pos recebe a posição do menor
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] < menor){// toda vida que o i for menor que o menor, o menor recebe o i
            menor = fila[i]; // menor recebendo i
            pos = i; // pos recebe i, que é a posição do menor
        }
    }
    return pos;// retorna a posição do menor
}

// procurar_pos_menor_apartir: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
int procurarPosMenorApartir(vector<int> fila, int pos){// pos vai ser o primeiro valor da fila 
    int menor = fila[pos]; // menor recebe o primeiro valor da fila
    int posMenor = pos; // posMenor recebe a posição do menor
    for(int i = pos; i < fila.size(); i++){// i começa na posição inicial
        if(fila[i] < menor){// toda vida que o i for menor que o menor, o menor recebe o i
            menor = fila[i]; // menor recebendo i
            posMenor = i; // posMenor recebe i, que é a posição do menor
        }
    }
    return posMenor;// retorna a posição do menor
}

// procurar_pos_melhor_se : qual a posição do HOMEM mais calmo ? (menor valor maior que 0)
int procurarPosMelhorSe(vector<int> fila){
    int menor = fila[0]; // menor recebe o primeiro valor da fila
    int pos = 0; // pos recebe a posição do menor
    for(int i = 0; i < fila.size(); i++){
        if(fila[i] > 0 && fila[i] < menor){// toda vida que o i for maior que 0 e menor que o menor, o menor recebe o i
            menor = fila[i]; // menor recebendo i
            pos = i; // pos recebe i, que é a posição do menor
        }
    }
    return pos;// retorna a posição do menor
}

// calcular_stress_medio: qual a média de stress da fila? (abs)
float stressMedio(vector<int> vec, int tam){
    float soma = 0, media = 0;
    for (int i = 0; i < vec.size(); ++i){
        if (vec[i] < 0){
            vec[i] *= -1; // o abs pega o modulo dos numeros
        }
        soma = vec[i] + soma;
    }
    media = soma / tam;
    return media;
}

char mHomemOuMulher(vector<int> vec){
    int Homem = 0, Mulher = 0, Empate = 0;
    for (int i = 0; i < vec.size(); ++i){
        if (vec[i] > 0){
            Homem++;
        }
        else if (vec[i] < 0){
            Mulher++;
        }
    }
    if (Homem > Mulher && Mulher < Homem){
        return 'H';
    }
    else if (Homem < Mulher && Mulher > Homem){
        return 'M';
    }
    else if (Homem == Mulher){
        return 'E';
    }
}

float maisEstressados(vector<int> vec, int size){
    float metade = vec.size() / 2;
    float somaP = 0, somaS = 0;
    for (int i = 0; i < metade; ++i){
        if (vec[i] < 0){
            vec[i] *= -1;
        }
        somaP = vec[i] + somaP;
    }

    for (int x = metade; x < vec.size(); ++x){
        if (vec[x] < 0){
            vec[x] *= -1;
        }
        somaS = vec[x] + somaS;
    }

    if (somaP > somaS && somaS < somaP){
        return 1;
    }
    else if (somaP < somaS && somaS > somaP){
        return 2;
    }
    else if (somaP == somaS){
        return -1;
    }
}

float homensMaisMulher(vector<int> vec){
    float somaH = 0, somaM, mediaH = 0, mediaM = 0;
    int contH = 0, contM = 0;
    for (int i = 0; i < vec.size(); ++i){
        if (vec[i] < 0){
            vec[i] *= -1;
            somaM = vec[i] + somaM;
            contM++;
        }
        else if (vec[i] > 0){
            somaH = vec[i] + somaH;
            contH++;
        }
    }
    mediaH = somaH / contH;
    mediaM = somaM / contM;

    if (mediaH > mediaM){
        return mediaH;
    }
    else {
        return -1;
    }
}