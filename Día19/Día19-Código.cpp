#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

unordered_map<string, int> memo; //Tabla hash de memoria para guardar los resultados de los subproblemas


bool CountWays(const vector<string>& words, const string& target) {
    if (memo.count(target)){ //Comprueba si el target ya ha sido calculado
        return memo[target];
    }
    if (target.empty()){
        return true;
    }
    
    bool posible = false;
    for (const string& word : words) {//Busca todas las palabras en el vector de palabras
        if (target.find(word) == 0) { //Comprueba si la palabra es un prefijo de target
            if (CountWays(words, target.substr(word.size()))) {
                posible = true;
                break;  
            }
        }
    }
    memo[target] = posible;
    return posible;
}


int main() {
    string D;
    ifstream infile("input.txt");
    vector<string> raw_lines;
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            raw_lines.push_back(line);
        }
    }
    infile.close();

    string temp_towels;
    vector<string> towels; 
    vector<string> designs;


    for (int i = 0; i < raw_lines.size(); i++) { //Separa towels de designs
        if (i == 0) {
            temp_towels = raw_lines[i];
        } else {
            if(raw_lines[i].empty()) continue;
            designs.push_back(raw_lines[i]);
           
        }
    }


    stringstream ss(temp_towels); 
    string word;

    while (getline(ss, word, ',')) {
        if (!word.empty() && word[0] == ' ') {
            word.erase(0, 1);
        }
        towels.push_back(word); 
    }//Separa las towels en un vector de strings a partir del ", "

    int ans = 0;
    for (const string& design : designs) {
        if (CountWays(towels, design)) {
            ans++;
        }
    }
    
    cout << ans<< endl;
    return 0;


   
}
