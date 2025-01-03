load("@rules_aws//tools:template_rule.bzl", "template_rule")

licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-common",
    srcs = glob([
        "source/posix/*.c",
        "source/*.c",
    ]) + [
        "source/external/cJSON.c",
    ] + select({
        "@platforms//cpu:x86_64": glob([
            "source/arch/intel/asm/*.c",
            "source/arch/intel/cpuid.c",
        ]),
        "@platforms//cpu:aarch64": glob([
            "source/arch/arm/asm/*.c",
            "source/arch/arm/cpuid.c",
        ]),
        "//conditions:default": [],
    }),
    hdrs = [
        "include/aws/common/config.h",
    ] + glob([
        "include/aws/common/*.h",
        "include/aws/common/posix/*.ini",
        "include/aws/common/external/*.h",
        "include/aws/common/private/*.h",
        "include/aws/common/**/*.inl",
    ]),
    copts = [
        "-DAWS_AFFINITY_METHOD=AWS_AFFINITY_METHOD_PTHREAD_ATTR",
        "-DCJSON_HIDE_SYMBOLS",
    ] + select({
        "@platforms//cpu:aarch64": [
            "-DAWS_HAVE_ARM64_CPU_FEATURE",
        ],
        "//conditions:default": [],
    }),
    includes = [
        "include/",
    ],
    linkopts = [
        "-lpthread",
    ],
    visibility = ["//visibility:public"],
)

template_rule(
    name = "config_h",
    src = "include/aws/common/config.h.in",
    out = "include/aws/common/config.h",
    substitutions = {
        "cmakedefine AWS_HAVE_GCC_OVERFLOW_MATH_EXTENSIONS": "undef AWS_HAVE_GCC_OVERFLOW_MATH_EXTENSIONS",
        "cmakedefine AWS_HAVE_GCC_INLINE_ASM": "define AWS_HAVE_GCC_INLINE_ASM",
        "cmakedefine AWS_HAVE_MSVC_MULX": "undef AWS_HAVE_MSVC_MULX",
        "cmakedefine AWS_HAVE_POSIX_LARGE_FILE_SUPPORT": "undef AWS_HAVE_POSIX_LARGE_FILE_SUPPORT",
        "cmakedefine AWS_HAVE_EXECINFO": "define AWS_HAVE_EXECINFO",
        "cmakedefine AWS_HAVE_WINAPI_DESKTOP": "undef AWS_HAVE_WINAPI_DESKTOP",
        "cmakedefine AWS_HAVE_LINUX_IF_LINK_H": "undef AWS_HAVE_LINUX_IF_LINK_H",
        "cmakedefine AWS_HAVE_MSVC_INTRINSICS_X64": "undef AWS_HAVE_MSVC_INTRINSICS_X64",
    },
)
