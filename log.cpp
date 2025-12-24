/*
* LOG PROBLEM
* Author : Sid Prasad
* Question 1
*/


/*
  <timestamp_ms> <user_id> <session_id> <event> [kv_pairs...]

  input file 

  n : entries
-------------------------------------------------
|  8
|  100 u1 s1 START
|  110 u1 s1 PAGE url=/home
|  120 u1 s1 CLICK id=btnA
|  150 u1 s1 PURCHASE amount=4999 item=X
|  160 u1 s1 END
|  90 u1 s2 PAGE url=/oops
|  200 u1 s2 START
|  250 u1 s2 END
|
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <cctype> 
#include <string>
#include <sstream>
#include <stdexcept>
#include <stack>

namespace SESH {
  enum class Event{
    START, PAGE, CLICK, PURCHASE, END
  };

  enum class State{
    IN, INVALID, OUT
  };
  enum class Code {
    READ_0, WRITE_0,
    READ_1, WRITE_1,
    LOG_0, LOG_1 
  };
};

template <typename K, typename V>
struct Event{
  K key_; 
  V value_;
};

struct Meta{
  double timestamp_ms;
  int user_id;
  int session_id;
  std::vector<int> linNo_;
  std::map<int, std::vector<std::vector<int>>> LogInts_;
  
};


class Log{
  public:
    explicit Log(const std::string& fname) : Filename(fname){}
    std::optional<SESH::Code> LogFileParser(char search_value){
        std::cout << "[ LogFileParser ]" << std::endl;
        std::ifstream file(Filename); // create instance of file
        if(!file.is_open()) { std::cerr << " Error opening file " << Filename << "\n"; return code::READ_1;}
        clearData();

        // put the whole file in the content string
        std::stringstream buffer_;
        buffer_ << file.rdbuf();
        std::string content = buffer_.str();

        std::vector<int> line_no;
        int curr_line = 1;
        for(const auto& c : content){
            line_no.push_back(curr_line);
            if (c == '\n') curr_line++;
        }
    auto code = Parse(content,line_no,search_value);
    std::cout <<  "PARSE ENDED WITH CODE"  << std::endl; 
  
    


     return code::READ_0;
  }         

  SESH::Code Parse(const std::string& content, const std::vector<int>& line_no, const char& search_value){
    // read the [] statements
    std::cout << "here" << std::endl;
    size_t position = 0;
    char complement;
    if (search_value != '[' && search_value != '<') return code::LOG_1;
    if (search_value == '[')  complement = ']';
    if (search_value == '<')  complement = '>';
        
        while(position < content.size()){
              auto left_bound = content.find(search_value, position);
              if(left_bound == std::string::npos) break;
              auto right_bound = content.find(complement, left_bound + 1);
              if(right_bound == std::string::npos) return code::READ_1;
              std::string inside = content.substr(left_bound+1, right_bound - left_bound - 1);
              std::stringstream ss(inside);
              std::vector<int>segments; int x;
              while(ss >> x ) segments.push_back(x);
              int start_line = line_no[left_bound];
              LogInts_[start_line].push_back(segments);
              position = right_bound + 1;
        }
      return code::LOG_0;
  }   



  
 void Print() {
    for(const auto& [line_num, list_of_lists] : LogInts_) {
        for(const auto& values : list_of_lists) {
            std::cout << "[ ";
            for(const auto& val : values) {
                std::cout << val << " ";
            }
            std::cout << "] ";
        }
        std::cout << "[line " << line_num << "]\n";
    }
  }
  std::map<int, std::vector<std::vector<int>>> getLogMap(){
    return LogInts_;
  }
  private:
    using code = SESH::Code;
    std::string Filename;
    std::vector<std::string> LogData_;
    std::map<int, std::vector<std::vector<int>>> LogInts_;
    
    void clearData(){
      LogInts_.clear();
    }

};

// Stores the meta data in a templated ring buffer (includes the data from < > and [ ])
class MetaRing{
  public:
    explicit MetaRing(int capacity) : size_(0), capacity_(capacity),
                                      tail_(0), head_(0),Ring_(nullptr) 
    {
      if(capacity_ == 0){
        throw std::runtime_error("capacity cannot be 0");
      }
      Ring_ = new Meta[capacity_];
    }
    /*
      double timestamp_ms;
      int user_id;
      int session_id;
      std::vector<int> linNo_;
      std::map<int, std::vector<std::vector<int>>> LogInts_;

      head_ = index where the next push/write will go
      tail_ = index where the next pop/read will come from
      size_ = number of valid elements in the buffer (0..capacity
      */ 

    void Push(Meta& obj){
      size_t push_index = head_;
      Ring_[push_index] = obj;

      if(size_ == capacity_){
        tail_ = (tail_ + 1) % capacity_;
      } else 
      {
        ++size_;
      }
    }

    Meta& Pop(){
      if (size_ == 0) throw std::runtime_error("empty ring buffer");
        Meta& x = Ring_[tail_];
        tail_ = (tail_ + 1) % capacity_;
        --size_;
        return x;
    }

  private:
    Meta *Ring_;
    size_t size_;
    size_t tail_;
    size_t head_;
    size_t capacity_;
};

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./log <file> <search_value> \n";
    return 1;
  }

  std::string filename = argv[1];
  char search_value = *argv[2];

  std::cout << search_value << std::endl;

  std::cout << filename << std::endl;
  Log logger(filename);
  logger.LogFileParser(search_value);
  logger.Print();

  //

  return 0;
}
