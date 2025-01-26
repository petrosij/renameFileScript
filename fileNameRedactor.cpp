#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <vector>
#include <cstdio>

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

    increaseNumberByN(s, 5, 10);
    cout << s << endl;

    string exeName("fileNameRedactor.exe");
    string path = _pgmptr;
    path.erase(path.find(exeName));
    cout << "path variable: " << path << endl;

    for (const auto & entry : directory_iterator(path)){
        cout << entry.path() << endl;
    }
    
    std::filesystem::path p = std::filesystem::current_path();
    const char* oldFilePath = "C:\\src\\projects\\renameFileScript\\1.txt"; 
    const char* newFilePath = "C:\\src\\projects\\renameFileScript\\11.txt"; 
    //ofstream fileObject {"C:\\src\\projects\\renameFileScript\\1.txt"};
    if (MoveFile (oldFilePath, newFilePath)){
        cout << "Successfully renamed" << endl;
    }else{
        DWORD errorCode = GetLastError();
        cerr << "Error renaming file code: " << errorCode << endl;
        printErrorMessage(errorCode);
    }
    //cout << "renameStatus: " << renameStatus << endl;
    

    return 0;
}