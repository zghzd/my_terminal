#pragma once
//����Ŀ��ȡ�ļ��ж�Ӧֵ
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // ���� std::isspace

// ����������ȥ���ַ������˵Ŀհ��ַ�
std::string trim(const std::string& str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    // �ҵ���һ���ǿհ��ַ�
    while (start <= end && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    // �ҵ����һ���ǿհ��ַ�
    while (end >= start && std::isspace(static_cast<unsigned char>(str[end])))
        --end;

    // ��������ַ������ǿհף��򷵻ؿ��ַ���
    if (start > end)
        return "";

    return str.substr(start, end - start + 1);
}
//�������ļ�������Ŀ����   ����ֵ����Ŀ���ƶ�Ӧֵ
std::string getConfigValue(const std::string& filename, const std::string& projectName) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // �ļ���ʧ�ܣ����ؿ��ַ���
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        // ��������
        if (line.empty())
            continue;

        // ���ҷָ���λ��
        size_t delimiter_pos = std::string::npos;
        for (size_t i = 0; i < line.length(); ++i) {
            if (line[i] == ':' || line[i] == '=') {
                delimiter_pos = i;
                break;
            }
        }

        // ���û���ҵ��ָ�������������
        if (delimiter_pos == std::string::npos)
            continue;

        // �ָ���Ŀ���ƺ�ֵ
        std::string key = trim(line.substr(0, delimiter_pos));
        std::string value = trim(line.substr(delimiter_pos + 1));

        // �����Ŀ�����Ƿ�ƥ��
        if (key == projectName) {
            file.close();
            return value;
        }
    }

    file.close();
    return ""; // δ�ҵ�ƥ����
}