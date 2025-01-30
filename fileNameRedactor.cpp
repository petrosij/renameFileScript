#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <vector>
#include <cstdio>
#include <cstdlib> //rand()???

using namespace std;
using namespace filesystem;



void increaseNumberByN(string& s , int numberToReplace, int increaseNum){
    s.replace(s.find(to_string(numberToReplace)), 1, to_string(numberToReplace+increaseNum));
}

void printErrorMessage(DWORD errorCode){
    LPVOID msgBuffer;
    DWORD  dw = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        (LPSTR)&msgBuffer,
        0, NULL);

        if (dw){

            SetConsoleOutputCP(CP_UTF8);
            //wcout << L"error: " << (wchar_t*)msgBuffer << endl;
            //wcout << L"Length of message: " << wcslen((wchar_t*)msgBuffer) << " symbols." << endl;


            cerr << "Error: " << (char*) msgBuffer << std::endl;
            LocalFree(msgBuffer);
        }else{
            cerr << "Not succeed obtaing error text. Error code: " << (char*) msgBuffer << std::endl;
        }

}

int main() {
    
    string s = "123456789";
    int renameStatus = 0;
    srand(time(NULL));
    increaseNumberByN(s, 5, 10);
    cout << s << endl;


    // string exeName("fileNameRedactor.exe");
    // string path_of_exe = _pgmptr;
    // path_of_exe.erase(path_of_exe.find(exeName));
    // cout << "path_of_exe variable (_pgmptr): " << path_of_exe << endl;


    
    std::filesystem::path p = std::filesystem::current_path();
    
  

    cout << "path_of_exe variable (std::filesystem::path p): " << p << endl;
    
    char* oldFilePath = "C:\\Users\\POSkudarnov\\source\\repos\\nameRedactor\\1.txt"; 
    string oldFileName(oldFilePath);
    char* newFilePath = "C:\\Users\\POSkudarnov\\source\\repos\\nameRedactor\\11.txt"; 
    string newFileName(newFilePath);
    //ofstream fileObject {"C:\\src\\projects\\renameFileScript\\1.txt"};
    if (MoveFile (oldFileName.c_str(), newFileName.c_str())){
        cout << "Successfully renamed" << endl;
    }else{
        DWORD errorCode = GetLastError();
        cerr << "Error renaming file code: " << errorCode << endl;
        printErrorMessage(errorCode);
    }
    //cout << "renameStatus: " << renameStatus << endl;
    
    std::error_code ec;

    for ( auto & entry : directory_iterator(p)){
        if (entry.path().filename().string().find(".txt") != std::string::npos){
            int rand = std::rand() % 10 + 1;
            cout << "rand: " << rand << endl;
            string  new_num_str = to_string(std::rand() % 10);
            cout << "new_num_str: " << new_num_str + ".txt" << endl;
            path old_path = entry.path().filename();
            path new_name = new_num_str + ".txt";
            rename(entry.path().string().c_str(), new_name.string().c_str());
        }
        cout << entry.path() << endl;
    }
    
    return 0;
}