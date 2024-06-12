# include <unordered_map>
# include <string>

using namespace std;

class Logger {
public:
    unordered_map<string, int> word_next_print_time;
    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (word_next_print_time.find(message) == word_next_print_time.end()) {
            // not find could print
            word_next_print_time[message] = timestamp + 10;
            return true;
        } else {
            int next_time = word_next_print_time[message];
            if (timestamp >= next_time) {
                word_next_print_time[message] = timestamp + 10;
                return true;
            } else {
                return false;
            }
        }

    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */