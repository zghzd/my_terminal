#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "my_terminal_processing.h"

int main(int argc, char* argv[]) {
	mainstart:
	std::string config_file = "mainconfig.config";
	if ((getConfigValue(config_file, "configtype") != "main") || (getConfigValue(config_file, "configkey") != "cbnatrjkhn01a1v7r3s1ca84VG14738TRD1tht73t1hgVTD1771T7863DXcvfg484r84x637g") ){
		cerr << "警告：main配置文件验证失败" << endl;
		int msg_getmainconfig = MessageBox(NULL, _T("main配置文件验证失败\n当你选择忽略时，程序将会继续运行，但是一些功能可能出现意外的结果\n选择中止以退出程序"), _T("警告"), MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		if (msg_getmainconfig == 3) {
			exit(-1);
		}
		else if (msg_getmainconfig == 4) {
			goto mainstart;
		}
		else if (msg_getmainconfig == 5) {
			cerr << "已忽略警告" << endl;
		}
		else {
			MessageBox(NULL, _T("一个错误导致返回值无法被处理\n程序将强制退出"), _T("错误"), MB_ICONSTOP);
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
		std::cout << "请输入指令:>";
		std::cin >> user_command_input;
		my_terminal_processing(user_command_input, is_debug, config_file);
	}
}