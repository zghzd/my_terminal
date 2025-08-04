#include <iostream>
#include "my_terminal_processing.h"

int main(int argc, char* argv[]) {
	std::string config_file = "mainconfig.config";
	if ((getConfigValue(config_file, "configtype") != "main") || (getConfigValue(config_file, "configkey") != "cbnatrjkhn01a1v7r3s1ca84VG14738TRD1tht73t1hgVTD1771T7863DXcvfg484r84x637g") ){
		cerr << "警告：main配置文件验证失败" << endl;
	}
	std::string user_command_input;
	bool is_debug = false;
	std::string argv_a = argv[1];
	if (argc > 1) {
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