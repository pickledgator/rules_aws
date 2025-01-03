load("@rules_aws//tools:template_rule.bzl", "template_rule")

licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-crt-cpp",
    srcs = glob([
        "source/**/*.cpp",
    ]),
    hdrs = glob([
        "include/aws/**/*.h",
    ]) + [
        "include/aws/crt/Config.h",
    ],
    copts = [
        "-Wno-stringop-overflow",
    ],
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-auth",
        "@aws-c-common",
        "@aws-c-event-stream",
        "@aws-c-http",
        "@aws-c-io",
        "@aws-c-mqtt",
        "@aws-c-s3",
        "@aws-checksums",
        "@aws-s2n",
    ],
)

template_rule(
    name = "Config_h",
    src = "include/aws/crt/Config.h.in",
    out = "include/aws/crt/Config.h",
    substitutions = {
        "cmakedefine": "define",
        "@AWS_CRT_CPP_VERSION@": "0.19.8",
    },
)
