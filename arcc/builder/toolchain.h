#pragma once

#include <string>

namespace arcc
{
	struct Toolchain
	{
		std::string _name;
		std::string _path;
		std::string _include_dir;

		void compile(const char* args);
	};
}