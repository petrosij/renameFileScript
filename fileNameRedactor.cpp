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

#define RENAME_CALL 1
#define EXIT_CALL 0

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
    
    int action;
    bool keep_on = true;
    string file_extension;
    int level_of_number;
    int lower_limit_of_number;
    int upper_limit_of_number;
    int increase_number;
    std::filesystem::path p = std::filesystem::current_path();
    
    while(keep_on){
        cout << "What would you like to do?" << endl;
        cout << "\t1. Rename file" << endl;
        cout << "\t0. Exit" << endl << "Your choice:";
        cin >> action; // Чтение символа

        if (cin.fail()){
            cout << "Input not an integer number.\nExiting programm..." << endl;
            return 1;
        }

        switch (action){
            case RENAME_CALL:
                cout << "Enter the extension of the file you want to rename: " << endl;
                cin >> file_extension;
                cout << "Choose the level of the number you want to replace:" << endl;
                cout << "Example: 10.13.66_DraftFile" + file_extension << endl;
                cout << "         |  |  |" << endl;
                cout << "         |  | \\/" << endl;
                cout << "         | \\/   Third level. Enter 3" << endl;
                cout << "        \\/   Second level. Enter 2" << endl;
                cout << "         First level. Enter 1" << endl;
                cout << "Your choice: ";
                cin >> level_of_number;
                cout << "Enter the the lower limit of the range: ";
                cin >> lower_limit_of_number;
                cout << "Enter the the upper limit of the range or press ENTER for renaming to the end of files list: ";
                cin >> upper_limit_of_number;
                cout << "Enter the number by which you want to increase the number: ";
                cin >> increase_number;




                for ( auto & entry : directory_iterator(p)){
                    if (entry.path().filename().string().find(file_extension) != std::string::npos){
                        string temp_string = entry.path().filename().string();
                        string name_without_numeration = temp_string.substr(temp_string.find('_'), temp_string.length() - temp_string.find('_') + 1);
                        string name_only_numeration = temp_string.substr(0, temp_string.find('_'));
                        cout << entry.path() << endl;
                        cout << "name_without_numeration: " << name_without_numeration << endl;
                        cout << "name_only_numeration: " << name_only_numeration << endl;

                        //while();
                        int number_of_levels_in_numeration;//?????????????????????
                        //vector<string,int> levels_in_numeration;
                        vector<int> numbers_in_numeration;
                        while(name_only_numeration.find('.') != std::string::npos){
                            numbers_in_numeration.push_back(stoi(name_only_numeration.substr(0, name_only_numeration.find('.'))));
                            name_only_numeration.erase(0, name_only_numeration.find('.') + 1);
                        }
                        numbers_in_numeration.push_back(stoi(name_only_numeration));                        

                        for (int i = 0; i < numbers_in_numeration.size(); i++) {
                            cout << "Vector elements: " << numbers_in_numeration[i] << endl;
                        }
                        cout << "TTTTTTT" << endl;
                        if ((numbers_in_numeration.size() >= level_of_number)&&
                        (numbers_in_numeration[level_of_number-1]<lower_limit_of_number)&&
                        (numbers_in_numeration[level_of_number-1]>=upper_limit_of_number)){
                            numbers_in_numeration[level_of_number - 1] += increase_number;
                        }

                        string  new_num_str;
                        for (int i = 0; i < numbers_in_numeration.size(); i++) {
                            if (i != numbers_in_numeration.size() - 1){
                                new_num_str += to_string(numbers_in_numeration[i]) + ".";
                            }else{
                            new_num_str += to_string(numbers_in_numeration[i]) + ".";
                            }     
                        }                   

                        cout << "new_num_str: " << new_num_str + name_without_numeration << endl;
                        path old_path = entry.path().filename();
                        path new_name = new_num_str + name_without_numeration;
                        rename(entry.path().string().c_str(), new_name.string().c_str());
                    }
                    
                }

                keep_on = false;
                break;
            case EXIT_CALL:
                cout << "Exit" << endl;
                
                keep_on = false;
                break;
            default:
                cout << "No such command. Try again." << endl;
        }
    }


    string s = "123456789";
    int renameStatus = 0;
    srand(time(NULL));
    increaseNumberByN(s, 5, 10);
    cout << s << endl;


    // string exeName("fileNameRedactor.exe");
    // string path_of_exe = _pgmptr;
    // path_of_exe.erase(path_of_exe.find(exeName));
    // cout << "path_of_exe variable (_pgmptr): " << path_of_exe << endl;


    //=========================================================================From here was commented
    // std::filesystem::path p = std::filesystem::current_path();
    
  

    // cout << "path_of_exe variable (std::filesystem::path p): " << p << endl;
    
    // char* oldFilePath = "C:\\Users\\POSkudarnov\\source\\repos\\nameRedactor\\1.txt"; 
    // string oldFileName(oldFilePath);
    // char* newFilePath = "C:\\Users\\POSkudarnov\\source\\repos\\nameRedactor\\11.txt"; 
    // string newFileName(newFilePath);
    // //ofstream fileObject {"C:\\src\\projects\\renameFileScript\\1.txt"};
    // if (MoveFile (oldFileName.c_str(), newFileName.c_str())){
    //     cout << "Successfully renamed" << endl;
    // }else{
    //     DWORD errorCode = GetLastError();
    //     cerr << "Error renaming file code: " << errorCode << endl;
    //     printErrorMessage(errorCode);
    // }
    // //cout << "renameStatus: " << renameStatus << endl;
    
    // std::error_code ec;

    // for ( auto & entry : directory_iterator(p)){
    //     if (entry.path().filename().string().find(".txt") != std::string::npos){
    //         int rand = std::rand() % 10 + 1;
    //         cout << "rand: " << rand << endl;
    //         string  new_num_str = to_string(std::rand() % 10);
    //         cout << "new_num_str: " << new_num_str + ".txt" << endl;
    //         path old_path = entry.path().filename();
    //         path new_name = new_num_str + ".txt";
    //         rename(entry.path().string().c_str(), new_name.string().c_str());
    //     }
    //     cout << entry.path() << endl;
    // }
    
    return 0;
}