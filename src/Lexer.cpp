#include "main.hpp"
#include <iostream>

// Token listesini konsola yazdırır
void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Token type: ";
        switch (token.type) {
            case TokenType::VAR: std::cout << "VAR"; break;
            case TokenType::IDENTIFIER: std::cout << "IDENTIFIER"; break;
            case TokenType::ASSIGN: std::cout << "ASSIGN"; break;
            case TokenType::INT_LITERAL: std::cout << "INT_LITERAL"; break;
            case TokenType::SEMICOLON: std::cout << "SEMICOLON"; break;
            default: std::cout << "UNKNOWN"; break;
        }
        std::cout << ", value: " << token.value << std::endl;
    }
}