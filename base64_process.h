#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

std::string base64_encode(const std::string& in, bool is_debug) {
    std::string out;
    int val = 0, valb = -6;
    for (size_t i = 0; i < in.size(); ++i) {
        unsigned char c = in[i];
        val = (val << 8) + c;
        valb += 8;
        if (is_debug) {
            std::cout << "编码字符: '" << c << "' (0x" << std::hex << (int)c << std::dec << "), val: " << val << ", valb: " << valb << std::endl;
        }
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            if (is_debug) {
                std::cout << "取6位: " << ((val >> valb) & 0x3F) << " -> '" << base64_chars[(val >> valb) & 0x3F] << "'\n";
            }
            valb -= 6;
        }
    }
    if (valb > -6) {
        out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
        if (is_debug) {
            std::cout << "补齐位: " << (((val << 8) >> (valb + 8)) & 0x3F) << " -> '" << base64_chars[((val << 8) >> (valb + 8)) & 0x3F] << "'\n";
        }
    }
    while (out.size() % 4) {
        out.push_back('=');
        if (is_debug) {
            std::cout << "补'='使长度为4的倍数\n";
        }
    }
    return out;
}

std::string base64_decode(const std::string& in, bool is_debug) {
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;

    std::string out;
    int val = 0, valb = -8;
    for (size_t i = 0; i < in.size(); ++i) {
        unsigned char c = in[i];
        if (T[c] == -1) {
            if (is_debug)
                std::cout << "遇到非base64字符或'=': '" << c << "'，忽略\n";
            continue;
        }
        val = (val << 6) + T[c];
        valb += 6;
        if (is_debug) {
            std::cout << "解码字符: '" << c << "', 累加val: " << val << ", valb: " << valb << std::endl;
        }
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            if (is_debug) {
                std::cout << "取8位: " << ((val >> valb) & 0xFF) << " -> '" << out.back() << "'\n";
            }
            valb -= 8;
        }
    }
    return out;
}

int base64_process(bool is_debug) {
    std::cout << "请选择操作：1-编码；2-解码: ";
    int mode = 0;
    std::cin >> mode;
    std::cin.ignore();
    std::string input;
    if (mode == 1) {
        std::cout << "请输入待编码字符串: ";
        std::getline(std::cin, input);
        if (is_debug) {
            std::cout << "开始Base64编码，输入内容: " << input << std::endl;
        }
        std::string encoded = base64_encode(input, is_debug);
        if (is_debug) {
            std::cout << "编码完成，Base64结果为: ";
        }
        std::cout << encoded << std::endl;
        return 0;
    }
    else if (mode == 2) {
        std::cout << "请输入待解码Base64字符串: ";
        std::getline(std::cin, input);
        if (is_debug) {
            std::cout << "开始Base64解码，输入内容: " << input << std::endl;
        }
        std::string decoded = base64_decode(input, is_debug);
        if (is_debug) {
            std::cout << "解码完成，原文为: ";
        }
        std::cout << decoded << std::endl;
        return 0;
    }
    else {
        std::cout << "无效选择！" << std::endl;
        return 1;
    }
}