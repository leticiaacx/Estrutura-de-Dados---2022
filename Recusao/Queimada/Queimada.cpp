#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<string> map)
{
    for (auto line : map){
        cout << line << endl;
        cout << endl;
    }
}

void queimar(vector<string> map, int lpos, int cpos)
{
   
    int nl =  map.size();
    int nc = map[0].size();

    if(lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc){
        return;
    }
    
    if(map[lpos][cpos] == '#'){
        map[lpos][cpos] = 'x'; // pegou fogo
        mostrar(map);
    }

    queimar(map, lpos, cpos - 1);
    queimar(map, lpos - 1, cpos);
    queimar(map, lpos, cpos + 1);
    queimar(map, lpos + 1, cpos);

    map[lpos][cpos] = '*';
    mostrar(map);
}

int main() 
{
    vector<string> map;
    ifstream arq("txt.queimada.txt");
    int nl { }, nc { }, li{ }, ci{ };
    arq >> nl >> nc >> li >> ci;

    string line;
    for(int i = 0; i < nl; i++){
        arq >> line;
        map.push_back(line);
    }
    
    queimar(map, li, ci);
    mostrar(map);
}