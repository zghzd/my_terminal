#pragma once
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include <iostream>
#include <windows.h>

using namespace std;

//�ļ���
int file_write_new(string file_name, string write_str) {
    
    ofstream outputFile;
    outputFile.open(file_name);
        if (outputFile.is_open()) {
           
            outputFile << write_str;
            outputFile.close();
            return 0;
            }
        else {
            cout << "�ļ���ʧ��" << endl;
            return -1;
        }
    
}
string file_read(string file_name) {
        ifstream f(file_name.c_str());
        std::ifstream fin(file_name);
        if (f.good()) {
            goto file_good;
        }
        else {
            return "�ļ���ʧ��\n";
        }
    file_good:
        if (fin.is_open()) {
            std::stringstream buffer;
            buffer << fin.rdbuf();
            std::string str(buffer.str());
            fin.close();
            return str;
        }
        else
        {
            cout << "�ļ���ʧ��" << endl;
            fin.close();
        }
   
}


int file_write_c(string file_name, string write_str) {

    ofstream outputFile;
    outputFile.open(file_name,ios_base::app);
    if (outputFile.is_open()) {

        outputFile << write_str;
        outputFile.close();
        return 0;
    }
    else {
        cout << "�ļ���ʧ��" << endl;
        return -1;
    }

}
