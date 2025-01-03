licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-event-stream",
    srcs = glob([
        "source/*.c",
    ]),
    hdrs = glob([
        "include/**/*.h",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
        "@aws-c-io",
        "@aws-checksums",
    ],
)
