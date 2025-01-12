#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class SuffixTree {
public:
    SuffixTree(const std::string& str) {
        build(str);
    }

    bool contains(const std::string& pattern) {
        return search(pattern);
    }

private:
    struct Node {
        std::vector<int> suffix_indices;
        std::unordered_map<char, Node*> children;
    };

    Node* root;

    void build(const std::string& str) {
        root = new Node();
        for (int i = 0; i < str.size(); ++i) {
            Node* current = root;
            for (int j = i; j < str.size(); ++j) {
                if (current->children.find(str[j]) == current->children.end()) {
                    current->children[str[j]] = new Node();
                }
                current = current->children[str[j]];
                current->suffix_indices.push_back(i);
            }
        }
    }

    bool search(const std::string& pattern) {
        Node* current = root;
        for (char c : pattern) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return !current->suffix_indices.empty();
    }
};

class AdventDay4 {
public:
    AdventDay4() {
        std::ifstream file("DatosXMAS.txt");
        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
            return;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            std::vector<char> row;
            for (char c : line) {
                if (c != '\n') row.push_back(c);
            }
            ws.push_back(row);
        }

        if (ws.empty()) {
            std::cerr << "El archivo está vacío o no contiene datos válidos." << std::endl;
            return;
        }

        n = ws.size();
        m = ws[0].size();
        word_goal = {"XMAS", "SAMX"};
        x_goal = {"MAS", "SAM"};
        part1 = 0;
        part2 = 0;
    }

    void xmas_search() {
        std::cout << "Iniciando búsqueda de XMAS..." << std::endl;
        row_search();
        col_search();
        diag_search();
    }

    void diag_x_mas_search() {
        std::cout << "Iniciando búsqueda de MAS en forma de X..." << std::endl;
        for (int row = 0; row < n - 2; ++row) {
            for (int col = 0; col < m - 2; ++col) {
                std::string diag_1 = {ws[row][col], ws[row + 1][col + 1], ws[row + 2][col + 2]};
                std::string diag_2 = {ws[row + 2][col], ws[row + 1][col + 1], ws[row][col + 2]};
                if (std::find(x_goal.begin(), x_goal.end(), diag_1) != x_goal.end() &&
                    std::find(x_goal.begin(), x_goal.end(), diag_2) != x_goal.end()) {
                    part2++;
                }
            }
        }
    }

    void print_results() {
        std::cout << "Resultados:" << std::endl;
        std::cout << "Parte 1: " << part1 << std::endl;
        std::cout << "Parte 2: " << part2 << std::endl;
    }

private:
    std::vector<std::vector<char>> ws;
    int n, m;
    std::vector<std::string> word_goal, x_goal;
    int part1, part2;

    void row_search() {
        for (const auto& row : ws) {
            std::string row_str(row.begin(), row.end());
            SuffixTree tree(row_str);
            for (const std::string& word : word_goal) {
                if (tree.contains(word)) {
                    part1++;
                }
            }
        }
    }

    void col_search() {
        for (int col = 0; col < m; ++col) {
            std::string col_str;
            for (int row = 0; row < n; ++row) {
                col_str += ws[row][col];
            }
            SuffixTree tree(col_str);
            for (const std::string& word : word_goal) {
                if (tree.contains(word)) {
                    part1++;
                }
            }
        }
    }

    void diag_search() {
        for (int row = 0; row <= n - 4; ++row) {
            for (int col = 0; col <= m - 4; ++col) {
                std::string diag_1 = {ws[row][col], ws[row + 1][col + 1], ws[row + 2][col + 2], ws[row + 3][col + 3]};
                std::string diag_2 = {ws[row + 3][col], ws[row + 2][col + 1], ws[row + 1][col + 2], ws[row][col + 3]};
                SuffixTree tree(diag_1);
                if (tree.contains("XMAS")) {
                    part1++;
                }
                SuffixTree tree2(diag_2);
                if (tree2.contains("XMAS")) {
                    part1++;
                }
            }
        }
    }
};

int main() {
    AdventDay4 day4;
    day4.xmas_search();
    day4.diag_x_mas_search();
    day4.print_results();
    return 0;
}
