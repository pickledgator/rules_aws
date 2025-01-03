licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-c-mqtt",
    srcs = glob([
        "source/*.c",
        "source/**/*.c",
    ]),
    hdrs = glob([
        "include/aws/mqtt/**/*.h",
    ]),
    copts = [
        "-DAWS_MQTT_WITH_WEBSOCKETS",
    ],
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
        "@aws-c-http",
        "@aws-c-io",
    ],
)
