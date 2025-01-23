#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>
#include <vector>

using namespace std;
using namespace filesystem;

void increaseNumberByN(string& s , int numberToReplace, int increaseNum){
    s.replace(s.find(to_string(numberToReplace)), 1, to_string(numberToReplace+increaseNum));
}

int main() {
    
    string s = "123456789";
    increaseNumberByN(s, 5, 10);
    cout << s << endl;

    string exeName("fileNameRedactor.exe");
    string path = _pgmptr;
    path.erase(path.find(exeName));
    cout << "path variable: " << path << endl;

    for (const auto & entry : directory_iterator(path)){
        
        std::cout << entry.path() << std::endl;
    }

    return 0;
}