#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>


int main(){
    std::vector<std::string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop",
        "ERROR: Network timeout"
    };

    std::shared_ptr<std::vector<std::string>> pLogs = std::make_shared<std::vector<std::string>>(logs);
    std::vector<std::string> errors;

    auto iserror = [](std::string& lg) -> bool {
        return (lg.find("ERROR:") != std::string::npos);
    };

    std::copy_if(pLogs -> begin(), pLogs -> end(), std::back_inserter(errors), iserror);
    std::sort(errors.begin(), errors.end());
    auto end = std::unique(errors.begin(), errors.end());
    errors.erase(end, errors.end());

    std::cout << "Original journal:\n";
    for (auto tp : *pLogs){
        std::cout << tp << "\n";
    }

    std::cout << "\nErrors:\n";
    for (auto error : errors){
        std::cout << error << "\n";
    }

    return 0;
}