#include <arcc/builder/builder.h>

void arcc::Builder::setup()
{

}

int arcc::Builder::run()
{
	return 0;
}

arcc::Target& arcc::Builder::add_executable(const char* name)
{
	auto target = std::make_unique<Target>(
		name,
		ETargetKind::Executable
	);
	auto* ptr = target.get();

	_targets.push_back(std::move(target));

	return *ptr;
}