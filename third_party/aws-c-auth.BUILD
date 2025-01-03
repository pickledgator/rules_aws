licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-auth",
    srcs = glob([
        "source/*.c",
    ]),
    hdrs = glob([
        "include/aws/auth/**/*.h",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-cal",
        "@aws-c-http",
        "@aws-c-sdkutils",
    ],
)
