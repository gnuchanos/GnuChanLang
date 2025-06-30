#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <vector>

// Token tipi için enum
enum class TokenType {
    VAR,
    IDENTIFIER,
    ASSIGN,
    INT_LITERAL,
    SEMICOLON,
    UNKNOWN
};

// Token struct: tür ve değeri tutar
struct Token {
    TokenType type;
    std::string value;

    // Yapıcılar
    Token(TokenType t, const std::string& v) : type(t), value(v) {}
    Token() : type(TokenType::UNKNOWN), value("") {}
};

// Fonksiyon prototipleri
std::string readFile(int argc, char* argv[]);
std::vector<Token> tokenizeInt(const std::string& source);
void printTokens(const std::vector<Token>& tokens);

#endif