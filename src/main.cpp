#include "main.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    // Dosyadan kaynak kodunu oku
    std::string code = readFile(argc, argv);
    if (code.empty()) {
        std::cerr << "Dosya okunamadı veya argüman eksik." << std::endl;
        return 1;
    }

    // Kaynak kodu ekrana bas (kontrol için)
    std::cout << "Dosya içeriği:\n" << code << std::endl;

    // Kaynak kodu tokenize et
    std::vector<Token> tokens = tokenizeInt(code);

    // Token listesini yazdır
    printTokens(tokens);

    return 0;
}