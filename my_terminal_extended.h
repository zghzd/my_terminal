#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

void my_terminal_extended(string dll_file_name, bool is_debug) {
    DWORD attributes = GetFileAttributesA(dll_file_name.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        if (is_debug) {
            cout << "DLL文件不存在: " << dll_file_name
                << " 错误码: " << GetLastError() << endl;
        }
        else {
            cout << "加载失败：文件不存在" << endl;
        }
        return;
    }
    if (attributes & FILE_ATTRIBUTE_DIRECTORY) {
        if (is_debug) {
            cout << "路径是目录而非文件: " << dll_file_name << endl;
        }
        else {
            cout << "加载失败：路径是目录" << endl;
        }
        return;
    }
    HMODULE hDLL = LoadLibraryA(dll_file_name.c_str());
    if (hDLL == NULL) {
        if (is_debug) {
            cout << "LoadLibrary失败，错误码: " << GetLastError() << endl;
        }
        else {
            cout << "加载失败" << endl;
        }
        return;
    }

    if (is_debug) {
        cout << "成功加载DLL: " << dll_file_name << endl;
    }
    typedef int (*DllExtendedFunc)();
    DllExtendedFunc dllExtended = (DllExtendedFunc)GetProcAddress(hDLL, "_dll_extended");
    if (dllExtended == NULL) {
        if (is_debug) {
            cout << "GetProcAddress失败，错误码: " << GetLastError() << endl;
        }
        else {
            cout << "加载失败" << endl;
        }
        FreeLibrary(hDLL);
        return;
    }

    if (is_debug) {
        cout << "成功获取函数地址" << endl;
    }
    int result = dllExtended();
    if (is_debug) {
        cout << "调用_dll_extended()返回结果: " << result << endl;
    }
    else {
        
    }
    FreeLibrary(hDLL);
}