#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

void my_terminal_extended(string dll_file_name, bool is_debug) {
    DWORD attributes = GetFileAttributesA(dll_file_name.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        if (is_debug) {
            cout << "DLL�ļ�������: " << dll_file_name
                << " ������: " << GetLastError() << endl;
        }
        else {
            cout << "����ʧ�ܣ��ļ�������" << endl;
        }
        return;
    }
    if (attributes & FILE_ATTRIBUTE_DIRECTORY) {
        if (is_debug) {
            cout << "·����Ŀ¼�����ļ�: " << dll_file_name << endl;
        }
        else {
            cout << "����ʧ�ܣ�·����Ŀ¼" << endl;
        }
        return;
    }
    HMODULE hDLL = LoadLibraryA(dll_file_name.c_str());
    if (hDLL == NULL) {
        if (is_debug) {
            cout << "LoadLibraryʧ�ܣ�������: " << GetLastError() << endl;
        }
        else {
            cout << "����ʧ��" << endl;
        }
        return;
    }

    if (is_debug) {
        cout << "�ɹ�����DLL: " << dll_file_name << endl;
    }
    typedef int (*DllExtendedFunc)();
    DllExtendedFunc dllExtended = (DllExtendedFunc)GetProcAddress(hDLL, "_dll_extended");
    if (dllExtended == NULL) {
        if (is_debug) {
            cout << "GetProcAddressʧ�ܣ�������: " << GetLastError() << endl;
        }
        else {
            cout << "����ʧ��" << endl;
        }
        FreeLibrary(hDLL);
        return;
    }

    if (is_debug) {
        cout << "�ɹ���ȡ������ַ" << endl;
    }
    int result = dllExtended();
    if (is_debug) {
        cout << "����_dll_extended()���ؽ��: " << result << endl;
    }
    else {
        
    }
    FreeLibrary(hDLL);
}