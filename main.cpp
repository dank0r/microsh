#include <iostream>
#include <unistd.h>
#include <string>

std::string getNextCommand(std::string &path, bool &is_root) {
	std::string cblue = "\x1B[1m\x1B[34m";
	std::string cnorm = "\x1B[0m";
	std::cout << cblue << path << cnorm << (is_root ? "! " : "> ");
	std::string input;
	std::cin >> input;
	return input;
}

int main(int argc, char **argv) {
	bool is_root = (geteuid() == 0);
	std::string path = get_current_dir_name();
	//std::cout << path << std::endl;
	//std::cout << is_root << std::endl;
	while(1)
	getNextCommand(path, is_root);
}
