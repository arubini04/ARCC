#pragma once

#include <string>
#include <vector>

namespace arcc
{
	enum class ETargetKind
	{
		Executable,
		StaticLib,
		DynamicLib
	};

	enum class ETargetPlatform
	{
		Unknown = -1,

		Windows,
		Linux
	};

	enum class ETargetCppStd
	{
		Cpp11 = 0,
		Cpp14,

		Default = Cpp11
	};

	struct Target
	{
		std::string              _name;
		ETargetKind              _kind;
		ETargetCppStd            _cpp_std;
		std::string              _compiler_flags;
		std::vector<std::string> _sources;
		std::vector<std::string> _public_include_dirs;
		std::vector<std::string> _private_include_dirs;
		std::vector<std::string> _dependencies;

		Target(const char* name, ETargetKind kind)
			: _name(name)
			, _kind(kind)
			, _cpp_std(ETargetCppStd::Default)
			, _compiler_flags()
			, _sources()
			, _public_include_dirs()
			, _private_include_dirs()
			, _dependencies()
		{ }

		//! Add target source files (.c, .cpp, etc...).
		Target& add_sources(std::vector<const char*>&& sources);
		
		Target& add_public_include_dirs(std::vector<const char*>&& include_dirs);

		Target& add_private_include_dirs(std::vector<const char*>&& include_dirs);

		Target& add_dependencies(std::vector<const char*>&& deps);
		
		Target& add_compiler_flags(const char* flags);

		Target& set_cpp_standard(ETargetCppStd cpp_std);
	};
}