licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-io",
    srcs = glob([
        "source/linux/*.c",
        "source/posix/*.c",
        "source/s2n/*.c",
        "source/*.c",
    ]),
    hdrs = glob([
        "include/aws/io/*.h",
        "include/aws/io/private/*.h",
        "source/pkcs11/v2.40/*.h",
    ]) + [
        "source/pkcs11_private.h",
    ],
    copts = [
        "-DEVENT_LOOP_DEFINE=EPOLL",
        "-DPLATFORM_LIBS=",
        "-DUSE_S2N",
    ],
    includes = [
        "include/",
    ],
    linkopts = [
        "-ldl",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-cal",
        "@aws-c-common",
        "@aws-s2n",
    ],
)
