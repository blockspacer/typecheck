#include "typecheck/debug.hpp"
#include <iostream>

void typecheck::_check(const bool b, const std::string msg, const std::string file, const int line) {
	if (!b) {
		std::cout << "Error occurred: [" << file << ":" << line << "]" << std::endl;
		throw std::runtime_error(msg);
	}
}