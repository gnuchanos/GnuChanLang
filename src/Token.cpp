#include "main.hpp"

// tokenizeInt: Temel olarak int ve bazı basit tokenlar çıkarır
std::vector<Token> tokenizeInt(const std::string& source) {
    std::vector<Token> tokens;
    size_t i = 0;

    while (i < source.size()) {
        if (isspace(source[i])) {
            i++;  // Boşlukları atla
            continue;
        }

        // "var" kelimesi
        if (source.compare(i, 3, "var") == 0) {
            tokens.push_back(Token(TokenType::VAR, "var"));
            i += 3;
            continue;
        }

        // Identifier (harf veya _ ile başlar, sonra harf/rakam/_)  
        if (isalpha(source[i]) || source[i] == '_') {
            size_t start = i;
            while (i < source.size() && (isalnum(source[i]) || source[i] == '_')) {
                i++;
            }
            tokens.push_back(Token(TokenType::IDENTIFIER, source.substr(start, i - start)));
            continue;
        }

        // Integer literal (sadece rakamlar)
        if (isdigit(source[i])) {
            size_t start = i;
            while (i < source.size() && isdigit(source[i])) {
                i++;
            }
            tokens.push_back(Token(TokenType::INT_LITERAL, source.substr(start, i - start)));
            continue;
        }

        // Atama operatörü "="
        if (source[i] == '=') {
            tokens.push_back(Token(TokenType::ASSIGN, "="));
            i++;
            continue;
        }

        // Noktalı virgül ";"
        if (source[i] == ';') {
            tokens.push_back(Token(TokenType::SEMICOLON, ";"));
            i++;
            continue;
        }

        // Bilinmeyen karakter
        tokens.push_back(Token(TokenType::UNKNOWN, std::string(1, source[i])));
        i++;
    }

    return tokens;
}