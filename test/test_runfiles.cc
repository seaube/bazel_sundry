#include "gtest/gtest.h"

#include <bazel_sundry/runfiles.hh>

TEST(BazelSundry, DefaultRunfiles) {
	auto runfiles = bazel_sundry::CreateDefaultRunfiles();
	ASSERT_TRUE(runfiles);
}
