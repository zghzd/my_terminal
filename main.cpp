#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "my_terminal_processing.h"

int main(int argc, char* argv[]) {
	mainstart:
	std::string config_file = "mainconfig.config";
	if ((getConfigValue(config_file, "configtype") != "main") || (getConfigValue(config_file, "configkey") != "cbnatrjkhn01a1v7r3s1ca84VG14738TRD1tht73t1hgVTD1771T7863DXcvfg484r84x637g") ){
		cerr << "���棺main�����ļ���֤ʧ��" << endl;
		int msg_getmainconfig = MessageBox(NULL, _T("main�����ļ���֤ʧ��\n����ѡ�����ʱ�����򽫻�������У�����һЩ���ܿ��ܳ�������Ľ��\nѡ����ֹ���˳�����"), _T("����"), MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		if (msg_getmainconfig == 3) {
			exit(-1);
		}
		else if (msg_getmainconfig == 4) {
			goto mainstart;
		}
		else if (msg_getmainconfig == 5) {
			cerr << "�Ѻ��Ծ���" << endl;
		}
		else {
			MessageBox(NULL, _T("һ�������·���ֵ�޷�������\n����ǿ���˳�"), _T("����"), MB_ICONSTOP);
			exit(-1);
		}
	}
	std::string user_command_input;
	bool is_debug = false;
	if (argc > 1) {
		std::string argv_a = argv[1];
		if (argv_a == "debug") {
			is_debug = true;
		}
	}
	while (true)
	{
		std::cout << "������ָ��:>";
		std::cin >> user_command_input;
		my_terminal_processing(user_command_input, is_debug, config_file);
	}
}