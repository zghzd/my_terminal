#pragma once
#include "my_terminal_IO.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#undef max
#include <Windows.h>

class my_compare {
private:
    string in_file_data_stringtext(bool is_debug) {
        string in_file_name;
        std::cout << "请输入文件名:>";
        std::cin >> in_file_name;
        return file_read(in_file_name);
    }
public:
    static void file_compare_stringtext(bool is_debug) {
        my_compare text_0, text_1;
        string text_a = text_0.in_file_data_stringtext(is_debug);
        string text_b = text_1.in_file_data_stringtext(is_debug);
        std::replace(text_b.begin(), text_b.end(), '\r', '\n');
        std::vector<std::string>text_compare_b;
        std::vector<std::string>text_compare_a;
        std::stringstream ss_a(text_a);
        std::string line;
        while (std::getline(ss_a, line)) {
            text_compare_a.push_back(line);
        }

        std::stringstream ss_b(text_b);
        while (std::getline(ss_b, line)) {
            text_compare_b.push_back(line);
        }
        for (size_t i = 0; i < text_compare_b.size(); ++i) {
            if (text_a.find(text_compare_b[i]) != string::npos) {
                auto new_end = std::remove(text_compare_a.begin(), text_compare_a.end(), text_compare_b[i]);
                text_compare_a.erase(new_end, text_compare_a.end());
            }
            else {
                std::cout << "+=" << text_compare_b[i] << std::endl;
            }
        }
        for (size_t i = 0; i < text_compare_a.size(); ++i) {
            std::cout << "-=" << text_compare_a[i] << std::endl;
        }
        text_compare_b.clear();
        text_compare_a.clear();
    }
};


    void mycompare(bool is_debug) {
        std::cout << "请指定模式:>";
        std::string mod_data;
        std::cin >> mod_data;
        if (mod_data == "stringtext") {
            my_compare::file_compare_stringtext(is_debug);
        }
    }
