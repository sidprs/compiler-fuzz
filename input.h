#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <stack>
     

enum TokenType{
  INT, CHAR, DOUBLE,
  FLOAT, BOOL, NTP
};


struct Token{
    TokenType type_;
    
};


class IO{
    public:
        explicit IO(size_t cap, size_t inst, std::string filename_);  
        using TokenList = std::vector<Token>;
        TokenList charToToken(char c, char next);
        void CacheToken();


    private:
        size_t instance_;
        size_t capacity_;
        std::string content_;

};
