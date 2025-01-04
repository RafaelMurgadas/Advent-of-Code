#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <cstring>

struct Position {
    int x, y;

    bool operator<(const Position& other) const {
        return (x < other.x)  (x == other.x && y < other.y);
    }
};

int main() {
    std::ifstream inputFile("input1.txt");


    std::vector<std::string> map;
    std::string line;
    while (std::getline(inputFile, line)) {
        map.push_back(line);
    }

 
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int direction = 0; 

    Position guard;
    std::set<Position> visited;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '^') {
                guard = {i, j};
                visited.insert(guard);
                map[i][j] = '.';
                break;
            }
        }
    }

    while (true) {
        int nextX = guard.x + dx[direction];
        int nextY = guard.y + dy[direction];

        if (nextX < 0  nextX >= map.size()  nextY < 0  nextY >= map[0].size()) {
            break;
        }

        if (map[nextX][nextY] == '#') {
            direction = (direction + 1) % 4; 
        } else {

            guard.x = nextX;
            guard.y = nextY;
            visited.insert(guard);
        }
    }

    std::cout << "Posiciones distintas visitadas: " << visited.size() << std::endl;

    return 0;
}
