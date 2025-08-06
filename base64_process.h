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
            std::cout << "�����ַ�: '" << c << "' (0x" << std::hex << (int)c << std::dec << "), val: " << val << ", valb: " << valb << std::endl;
        }
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            if (is_debug) {
                std::cout << "ȡ6λ: " << ((val >> valb) & 0x3F) << " -> '" << base64_chars[(val >> valb) & 0x3F] << "'\n";
            }
            valb -= 6;
        }
    }
    if (valb > -6) {
        out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
        if (is_debug) {
            std::cout << "����λ: " << (((val << 8) >> (valb + 8)) & 0x3F) << " -> '" << base64_chars[((val << 8) >> (valb + 8)) & 0x3F] << "'\n";
        }
    }
    while (out.size() % 4) {
        out.push_back('=');
        if (is_debug) {
            std::cout << "��'='ʹ����Ϊ4�ı���\n";
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
                std::cout << "������base64�ַ���'=': '" << c << "'������\n";
            continue;
        }
        val = (val << 6) + T[c];
        valb += 6;
        if (is_debug) {
            std::cout << "�����ַ�: '" << c << "', �ۼ�val: " << val << ", valb: " << valb << std::endl;
        }
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            if (is_debug) {
                std::cout << "ȡ8λ: " << ((val >> valb) & 0xFF) << " -> '" << out.back() << "'\n";
            }
            valb -= 8;
        }
    }
    return out;
}

int base64_process(bool is_debug) {
    std::cout << "��ѡ�������1-���룻2-����: ";
    int mode = 0;
    std::cin >> mode;
    std::cin.ignore();
    std::string input;
    if (mode == 1) {
        std::cout << "������������ַ���: ";
        std::getline(std::cin, input);
        if (is_debug) {
            std::cout << "��ʼBase64���룬��������: " << input << std::endl;
        }
        std::string encoded = base64_encode(input, is_debug);
        if (is_debug) {
            std::cout << "������ɣ�Base64���Ϊ: ";
        }
        std::cout << encoded << std::endl;
        return 0;
    }
    else if (mode == 2) {
        std::cout << "�����������Base64�ַ���: ";
        std::getline(std::cin, input);
        if (is_debug) {
            std::cout << "��ʼBase64���룬��������: " << input << std::endl;
        }
        std::string decoded = base64_decode(input, is_debug);
        if (is_debug) {
            std::cout << "������ɣ�ԭ��Ϊ: ";
        }
        std::cout << decoded << std::endl;
        return 0;
    }
    else {
        std::cout << "��Чѡ��" << std::endl;
        return 1;
    }
}