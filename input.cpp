#include "input.h"


IO::IO(size_t cap, size_t inst, std::string filename_) :instance_(inst),capacity_(cap) {
            std::ifstream file_(filename_);
            std::stringstream buffer_;
            buffer_ << file_.rdbuf();
            std::string content_ = buffer_.str();
}


void IO::Tokenize(){
    
}

TokenType charToToken(char c, char next) {
    switch (c) {
        case '+':
            if (next == '+') return TOKEN_PLUS_PLUS;
            if (next == '=') return TOKEN_PLUS_EQUAL;
            return TOKEN_PLUS;
            
        case '-':
            if (next == '-') return TOKEN_MINUS_MINUS;
            if (next == '=') return TOKEN_MINUS_EQUAL;
            if (next == '>') return TOKEN_ARROW;
            return TOKEN_MINUS;
            
        case '*':
            if (next == '=') return TOKEN_STAR_EQUAL;
            return TOKEN_STAR;
            
        case '/':
            if (next == '=') return TOKEN_SLASH_EQUAL;
            return TOKEN_SLASH;
            
        case '%':
            if (next == '=') return TOKEN_PERCENT_EQUAL;
            return TOKEN_PERCENT;
            
        case '=':
            if (next == '=') return TOKEN_EQUAL_EQUAL;
            return TOKEN_EQUAL;
            
        case '!':
            if (next == '=') return TOKEN_NOT_EQUAL;
            return TOKEN_NOT;
            
        case '<':
            if (next == '=') return TOKEN_LESS_EQUAL;
            if (next == '<') return TOKEN_LEFT_SHIFT;
            return TOKEN_LESS;
            
        case '>':
            if (next == '=') return TOKEN_GREATER_EQUAL;
            if (next == '>') return TOKEN_RIGHT_SHIFT;
            return TOKEN_GREATER;
            
        case '&':
            if (next == '&') return TOKEN_AND_AND;
            if (next == '=') return TOKEN_AND_EQUAL;
            return TOKEN_AND;
            
        case '|':
            if (next == '|') return TOKEN_OR_OR;
            if (next == '=') return TOKEN_OR_EQUAL;
            return TOKEN_OR;
            
        case '^':
            if (next == '=') return TOKEN_XOR_EQUAL;
            return TOKEN_XOR;
            
        case '~':
            return TOKEN_TILDE;
            
        case '(':
            return TOKEN_LEFT_PAREN;
            
        case ')':
            return TOKEN_RIGHT_PAREN;
            
        case '{':
            return TOKEN_LEFT_BRACE;
            
        case '}':
            return TOKEN_RIGHT_BRACE;
            
        case '[':
            return TOKEN_LEFT_BRACKET;
            
        case ']':
            return TOKEN_RIGHT_BRACKET;
            
        case ';':
            return TOKEN_SEMICOLON;
            
        case ',':
            return TOKEN_COMMA;
            
        case '.':
            return TOKEN_DOT;
            
        case ':':
            return TOKEN_COLON;
            
        case '?':
            return TOKEN_QUESTION;
            
        case '#':
            if (next == '#') return TOKEN_HASH_HASH;
            return TOKEN_HASH;
            
        default:
            return TOKEN_UNKNOWN;
    }
}
