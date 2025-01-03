licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-cal",
    srcs = glob([
        "source/*.c",
        "source/unix/*.c",
    ]),
    hdrs = glob([
        "include/aws/cal/**/*.h",
    ]),
    defines = [
        "OPENSSL_IS_AWSLC",
    ],
    includes = [
        "include/",
    ],
    linkopts = [
        "-lpthread",
        "-ldl",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
        "@boringssl//:crypto",
        "@boringssl//:ssl",
    ],
)
