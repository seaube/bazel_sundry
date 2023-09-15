load("@bazel_skylib//lib:selects.bzl", "selects")

copts = selects.with_or({
    ("@rules_cc//cc/compiler:clang"): [
        "-std=c++2b",
        "-fexperimental-library",
    ],
    ("@rules_cc//cc/compiler:msvc-cl", "@rules_cc//cc/compiler:clang-cl"): [
        "/std:c++latest",
        "/permissive-",
        "/Zc:preprocessor",
    ],
})
