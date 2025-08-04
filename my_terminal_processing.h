#pragma once
#include <iostream>
#include "my_terminal_extended.h"
#include "fileread_withkey.h"

void my_terminal_processing(std::string user_command, bool is_debug = false, string config_file = "config.config") {
	if (user_command == "extended") {
		std::string dll_file_name = getConfigValue(config_file, "extended_dll");
		std::string extended_enable = getConfigValue(config_file, "extended_enable");
		if (extended_enable != "y") {
			std::cout << "没有启用extended功能" << std::endl;
			return;
		}
		my_terminal_extended(dll_file_name, is_debug);
	}
	else {
		std::cout << "未知指令" << std::endl;
		return;
	}
	return;
}