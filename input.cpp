#include "input.h"


IO::IO(size_t cap, size_t inst, std::string filename_) :instance_(inst),capacity_(cap) {
            std::ifstream file_(filename_);
            std::stringstream buffer_;
            buffer_ << file_.rdbuf();
            std::string content_ = buffer_.str();
}


void IO::Tokenize(){
    
}