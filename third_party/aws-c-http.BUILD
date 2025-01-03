licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-http",
    srcs = glob([
        "source/*.c",
    ]),
    hdrs = glob([
        "include/aws/http/**/*.h",
        "include/aws/http/private/*.def",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-compression",
        "@aws-c-io",
    ],
)
