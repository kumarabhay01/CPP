#include <fstream>
#include <string>
#include<iostream>

using namespace std;

int main() {
    std::ifstream infile("thefile.txt");
    std::string line;
    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
        }
    }
    infile.close();

    ofstream outFile;
    outFile.open("thefile.txt", ios::app);
    if (outFile.is_open())
        outFile << "This is new line";
    outFile.close();

    return 0;
}
