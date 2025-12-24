#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <stack>

enum TokenType {
    // End of file
    TOKEN_EOF,
    
    // Literals
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_CHAR,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    
    // Identifiers and keywords
    TOKEN_IDENTIFIER,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_DO,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_DEFAULT,
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_RETURN,
    TOKEN_GOTO,
    
    // Types
    TOKEN_INT,
    TOKEN_FLOAT_TYPE,
    TOKEN_DOUBLE,
    TOKEN_CHAR_TYPE,
    TOKEN_VOID,
    TOKEN_BOOL,
    TOKEN_LONG,
    TOKEN_SHORT,
    TOKEN_UNSIGNED,
    TOKEN_SIGNED,
    TOKEN_STRUCT,
    TOKEN_UNION,
    TOKEN_ENUM,
    TOKEN_TYPEDEF,
    
    // Storage classes
    TOKEN_STATIC,
    TOKEN_EXTERN,
    TOKEN_AUTO,
    TOKEN_REGISTER,
    TOKEN_CONST,
    TOKEN_VOLATILE,
    
    // Operators - Arithmetic
    TOKEN_PLUS,           // +
    TOKEN_MINUS,          // -
    TOKEN_STAR,           // *
    TOKEN_SLASH,          // /
    TOKEN_PERCENT,        // %
    TOKEN_PLUS_PLUS,      // ++
    TOKEN_MINUS_MINUS,    // --
    
    // Operators - Relational
    TOKEN_EQUAL_EQUAL,    // ==
    TOKEN_NOT_EQUAL,      // !=
    TOKEN_LESS,           // 
    TOKEN_LESS_EQUAL,     // <=
    TOKEN_GREATER,        // >
    TOKEN_GREATER_EQUAL,  // >=
    
    // Operators - Logical
    TOKEN_AND_AND,        // &&
    TOKEN_OR_OR,          // ||
    TOKEN_NOT,            // !
    
    // Operators - Bitwise
    TOKEN_AND,            // &
    TOKEN_OR,             // |
    TOKEN_XOR,            // ^
    TOKEN_TILDE,          // ~
    TOKEN_LEFT_SHIFT,     // 
    TOKEN_RIGHT_SHIFT,    // >>
    
    // Operators - Assignment
    TOKEN_EQUAL,          // =
    TOKEN_PLUS_EQUAL,     // +=
    TOKEN_MINUS_EQUAL,    // -=
    TOKEN_STAR_EQUAL,     // *=
    TOKEN_SLASH_EQUAL,    // /=
    TOKEN_PERCENT_EQUAL,  // %=
    TOKEN_AND_EQUAL,      // &=
    TOKEN_OR_EQUAL,       // |=
    TOKEN_XOR_EQUAL,      // ^=
    TOKEN_LEFT_SHIFT_EQUAL,  // <<=
    TOKEN_RIGHT_SHIFT_EQUAL, // >>=
    
    // Delimiters
    TOKEN_LEFT_PAREN,     // (
    TOKEN_RIGHT_PAREN,    // )
    TOKEN_LEFT_BRACE,     // {
    TOKEN_RIGHT_BRACE,    // }
    TOKEN_LEFT_BRACKET,   // [
    TOKEN_RIGHT_BRACKET,  // ]
    TOKEN_SEMICOLON,      // ;
    TOKEN_COMMA,          // ,
    TOKEN_DOT,            // .
    TOKEN_ARROW,          // ->
    TOKEN_COLON,          // :
    TOKEN_QUESTION,       // ?
    
    // Preprocessor (if handling)
    TOKEN_HASH,           // #
    TOKEN_HASH_HASH,      // ##
    
    // Special
    TOKEN_SIZEOF,
    TOKEN_ELLIPSIS,       // ...
    
    // Error token
    TOKEN_ERROR,
    TOKEN_UNKNOWN
};

struct Token{
    TokenType type_;
    
};

using TokenList = std::vector<Token>;

class IO{
    public:
        explicit IO(size_t cap, size_t inst, std::string filename_);
        TokenType charToToken(char c, char next);



    private:
        size_t instance_;
        size_t capacity_;
        std::string content_;


};
