licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-compression",
    srcs = glob([
        "source/**/*.c",
    ]),
    hdrs = glob([
        "include/aws/compression/**/*.h",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
    ],
)