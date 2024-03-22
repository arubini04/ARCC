#include <arcc/builder/target.h>

arcc::Target& arcc::Target::add_sources(std::vector<const char*>&& sources)
{
	for (auto s : sources)
	{
		_sources.push_back(s);
	}

	return *this;
}

arcc::Target& arcc::Target::add_public_include_dirs(std::vector<const char*>&& include_dirs)
{
	for (auto s : include_dirs)
	{
		_public_include_dirs.push_back(s);
	}

	return *this;
}

arcc::Target& arcc::Target::add_private_include_dirs(std::vector<const char*>&& include_dirs)
{
	for (auto s : include_dirs)
	{
		_private_include_dirs.push_back(s);
	}

	return *this;
}

arcc::Target& arcc::Target::add_dependencies(std::vector<const char*>&& deps)
{
	for (auto s : deps)
	{
		_dependencies.push_back(s);
	}

	return *this;
}

arcc::Target& arcc::Target::add_compiler_flags(const char* flags)
{
	_compiler_flags = std::move(flags);

	return *this;
}

arcc::Target& arcc::Target::set_cpp_standard(ETargetCppStd cpp_std)
{
	_cpp_std = cpp_std;

	return *this;
}