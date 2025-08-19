#pragma once
#include "my_terminal_IO.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#undef max
#include <Windows.h>

class my_compare {
private:
    string in_file_data_stringtext(bool is_debug) {
        string in_file_name;
        std::cout << "请输入文件名:\n";
        std::cin >> in_file_name;
        return file_read(in_file_name);
    }
    pair<int, pair<int, int>> findLongestCommonSubstring(const string& s1, const string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int max_len = 0, end1 = 0, end2 = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        end1 = i;
                        end2 = j;
                    }
                }
            }
        }
        return { max_len, {end1 - max_len, end2 - max_len} };
    }
public:
    static void file_compare_stringtext(bool is_debug) {
        my_compare text_0, text_1, findLongestCommonSubstring_;
        string text_a = text_0.in_file_data_stringtext(is_debug);
        string text_b = text_1.in_file_data_stringtext(is_debug);
        auto splitToLines = [](const string& input) {
            vector<string> lines;
            istringstream iss(input);
            string line;
            while (getline(iss, line)) {
                lines.push_back(line);
            }
            return lines;
            };
        vector<string> lines_a = splitToLines(text_a);
        vector<string> lines_b = splitToLines(text_b);
        size_t max_lines = max(lines_a.size(), lines_b.size());
        cout << "base=first file\n";
        for (size_t i = 0; i < max_lines; ++i) {
            string s1 = (i < lines_a.size()) ? lines_a[i] : "";
            string s2 = (i < lines_b.size()) ? lines_b[i] : "";
            if (i < lines_a.size() && i < lines_b.size()) {
                auto result = findLongestCommonSubstring_.findLongestCommonSubstring(s1, s2);
                int len = result.first;
                auto pos = result.second;
                int start1 = pos.first;
                int start2 = pos.second;
                string removed = s1.substr(0, start1);
                string added = s2.substr(start2 + len);
                cout << "Line " << i + 1 << ":\n-=" << removed << "\n+=" << added << endl;
            }
            else if (i < lines_a.size()) {
                cout << "Line " << i + 1 << " (only in base):\n-=" << s1 << "\n+=" << endl;
            }
            else {
                cout << "Line " << i + 1 << " (only in other):\n-=\n+=" << s2 << endl;
            }
        }
    }
};


    void mycompare(bool is_debug) {
        std::cout << "请指定模式:\n";
        std::string mod_data;
        std::cin >> mod_data;
        if (mod_data == "stringtext") {
            my_compare::file_compare_stringtext(is_debug);
        }
    }
