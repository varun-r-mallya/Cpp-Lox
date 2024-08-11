#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Lox.hpp"

#define Object std::string

enum TokenType {
    // Single-character tokens.
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    // One or two character tokens.
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    // Literals.
    IDENTIFIER,
    STRING,
    NUMBER,

    // Keywords.
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    VAR,
    WHILE,

    EndOfFile // TODO: Alias for EOF, find ways to rename this to EOF by using #undef
};

class Token {
public:
    TokenType type;
    std::string lexeme;
    Object literal;
    int line;

    Token(TokenType type, std::string lexeme, Object literal, int line);

    [[nodiscard]] std::string toString() const;
};

class Scanner {
private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;    // points to the first character of the string being processed
    int current = 0;  // points to the current character being processed
    int line = 1;     // tracks the source line
    char advance();   // goes one character ahead and returns it
    bool match(char); // Matches characters with EOL error handling inbuilt
    Lox LoxObject;    // creates a Lox object for error reporting
    bool isAtEnd();   // just checks if we have reached the EOL
    char peek();      // if it is at the end, then return \0 else returns the current character without consuming it

public:
    explicit Scanner(std::string);

    std::vector<Token> scanTokens();

    void scanToken();

    void
    addToken(TokenType type, Object literal = ""); // TODO: replace this Object literal with a NULL like empty object
};