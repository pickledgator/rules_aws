licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-s3",
    srcs = glob([
        "source/*.c",
    ]),
    hdrs = glob([
        "include/aws/s3/**/*.h",
    ]),
    copts = [
        "-DCJSON_HIDE_SYMBOLS",
    ],
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-auth",
        "@aws-checksums",
    ],
)
