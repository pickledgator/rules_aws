licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-sdkutils",
    srcs = glob([
        "source/*.c",
    ]),
    hdrs = glob([
        "include/aws/sdkutils/private/*.h",
        "include/aws/sdkutils/*.h",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
    ],
)
