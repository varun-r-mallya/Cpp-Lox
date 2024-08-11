#include "Scanner.hpp"
#include <iostream>
#include <utility>

std::string Token::toString() const {
    return to_string(type) + " " + lexeme + " " + literal;
}

Token::Token(TokenType type, std::string lexeme, Object literal, int line) {
    (*this).type = type;
    (*this).lexeme = std::move(lexeme);
    (*this).literal = std::move(literal);
    (*this).line = line;
}

bool Scanner::isAtEnd() {
    return (current >= source.length());
}

Scanner::Scanner(std::string source) {
    (*this).source = std::move(source);
}

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    Token EOFToken(EndOfFile, "", "", line); // TODO: replace the literal with a NULL like object like in java
    tokens.push_back(EOFToken);
    return tokens;
}

void Scanner::scanToken() {
    char c = advance();
    switch (c) {
        case '(':
            addToken(LEFT_PAREN);
            break;
        case ')':
            addToken(RIGHT_PAREN);
            break;
        case '{':
            addToken(LEFT_BRACE);
            break;
        case '}':
            addToken(RIGHT_BRACE);
            break;
        case ',':
            addToken(COMMA);
            break;
        case '.':
            addToken(DOT);
            break;
        case '-':
            addToken(MINUS);
            break;
        case '+':
            addToken(PLUS);
            break;
        case ';':
            addToken(SEMICOLON);
            break;
        case '*':
            addToken(STAR);
            break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '/':
            if (match('/')) {
                // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd())
                    advance();
            } else {
                addToken(SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;
        case '\n':
            line++;
            break;
        default:
            LoxObject.error("Unexpected character.", line);
            break;
    }
}

char Scanner::advance() {
    char curr = source[current];
    if (!isAtEnd())
        current++;
    return curr;
}

void Scanner::addToken(TokenType type, Object literal) {
    std::string text = source.substr(start, current - start);
    Token t(type, text, std::move(literal), line);
    tokens.push_back(t);
}

bool Scanner::match(char expected) {
    if (isAtEnd()) {
        return false;
    }
    if (source[current] != expected) {
        return false;
    }
    current++;
    return true;
}

// this uses a concept called lookahead
char Scanner::peek() {
    if (isAtEnd())
        return '\0';
    return source[current];
}
