licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

config_setting(
    name = "opt_mode",
    values = {"compilation_mode": "opt"},
)

cc_library(
    name = "aws-checksums",
    srcs = glob([
        "source/*.c",
    ]) + select({
        "@platforms//cpu:x86_64": glob(["source/intel/asm/*.c"]),
        "@platforms//cpu:aarch64": glob(["source/arm/*.c"]),
        "//conditions:default": [],
    }),
    hdrs = [
        "include/aws/checksums/crc.h",
        "include/aws/checksums/exports.h",
        "include/aws/checksums/private/crc_priv.h",
    ],
    copts = select({
        "@platforms//cpu:aarch64": [
            "-march=armv8-a+crc",
            "-mtune=generic",
            "-DAWS_HAVE_ARM64_CRC",
            "-DAWS_HAVE_ARM64_NEON",
            "-DAWS_HAVE_ARM64_CPU_FEATURE",
        ],
        "//conditions:default": [],
    }),
    defines = select({
        ":opt_mode": [],
        "//conditions:default": ["DEBUG_BUILD"],
    }),
    includes = [
        "include/",
    ],
    linkopts = [
        "-ldl",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
    ],
)
