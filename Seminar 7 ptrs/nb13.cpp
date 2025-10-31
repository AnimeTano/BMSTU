#include <iostream>
#include <vector>


void parseTelemetry(const char* data){
    const char* p = data;

    while (*p != '\0'){
        const char* word_start = p;

        while (*p != ':' && *p != '\0') p++;

        const char* word_end = p;

        p++;
        
        const char* value_start = p;

        while (*p != ';' && *p != '\0') p++;

        const char * value_end = p;

        for (const char* i = word_start; i < word_end; i++){
            std::cout << *i;
        } std::cout << ": ";

        for (const char* i = value_start; i < value_end; i++){
            std::cout << *i;
        } std::cout << "\n";

        if (*p != '\0') p++;
    }
}

int main(){
    const char* str = "TEMP:24.5;PRESS:101.3;HUM:55.2";
    parseTelemetry(str);

    return 0;
}