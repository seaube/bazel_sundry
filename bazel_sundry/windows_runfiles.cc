#include <windows.h>

#include <string>
#include <bazel_sundry/runfiles.hh>

using bazel_sundry::Runfiles;

std::unique_ptr<Runfiles> bazel_sundry::CreateDefaultRunfiles() {
	char result[MAX_PATH];
	size_t length = GetModuleFileName(NULL, result, MAX_PATH);
	if(length == 0) {
		return nullptr;
	}

	Runfiles* runfiles = Runfiles::Create(std::string(result));
	if(!runfiles) {
		return nullptr;
	}

	return std::unique_ptr<Runfiles>(runfiles);
}
