#pragma once

#include <arcc/builder/target.h>
#include <arcc/builder/toolchain.h>

#include <memory>

namespace arcc
{
	struct Builder
	{
		std::vector<std::unique_ptr<Target>> _targets;
		std::vector<Toolchain>               _toolchains;

		//! Find all toolchain on the current machine.
		void setup();

		//! Compile the project.
		//!
		//! @return Compiler result status.
		int run();

		//! Create a new executable.
		//!
		//! @param name Executable name.
		//! 
		//! @return Non-owned pointer to the created target.
		Target& add_executable(const char* name);

	};
}