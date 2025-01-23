#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;
using namespace filesystem;

int main() {
    
    string exeName("fileNameRedactor.exe");
    string path = _pgmptr;
    path.erase(path.find(exeName));
    cout << "path variable: " << path << endl;
    for (const auto & entry : directory_iterator(path)){
        std::cout << entry.path() << std::endl;
    }

    return 0;
}