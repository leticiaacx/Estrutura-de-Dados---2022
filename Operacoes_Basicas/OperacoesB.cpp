#include <sstream>  
#include <iostream> 
#include <vector>   

using namespace std;

int sum(vector<int> v) { // a soma dos elementos
    return (v.size() == 1) ? v[0] : v[0] + sum(vector<int>(v.begin() + 1, v.end()));
}

void print(vector<int> v){
    if (v.size() == 1)
        cout << v[0] << endl;

    cout << v[0] << " ";
    print(vector<int>(v.begin() + 1, v.end()));
}


void printReverse(vector<int> v, int n) { // o vetor impresso ao contrário
    if (n == 0)
        return;

    cout << v[n - 1] << " ";
    printReverse(v, n - 1);
}

int multiplication(vector<int> v, int n) { // a multiplicação dos elementos
    return (n == 0) ? 1 : v[n - 1] * multiplication(v, n - 1);
}

int minimum(vector<int> v, int n, int min) { // o menor elemento 
    if (n == 0) return min;

    if (v[n - 1] < min)
        min = v[n - 1];

    return minimum(v, n - 1, min);
}


void reverse(vector<int> &vet, int pos = 0){
    if (pos >= vet.size() / 2)
        return;

    swap(vet[pos], vet[vet.size() - 1 - pos]);
    reverse(vet, pos + 1);
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;

    while (ss >> value)
        vet.push_back(value);
    // cout << sum(vet) << endl;
    // print(vet);
    // printReverse(vet, vet.size());
    // cout << multiplication(vet, vet.size()) << endl;
    // cout << minimum(vet, vet.size(), vet[0]) << endl;
    reverse(vet);
    print(vet);
}