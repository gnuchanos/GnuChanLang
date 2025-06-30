#include "main.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Dosya okuma fonksiyonu
std::string readFile(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./program <file_name.gc>" << std::endl;
        return "";
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return "";
    }

    std::ostringstream oss;
    oss << file.rdbuf();  // Tüm dosya içeriğini oku
    return oss.str();
}