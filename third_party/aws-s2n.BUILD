licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_library(
    name = "aws-s2n",
    srcs = glob([
        "crypto/*.c",
        "error/*.c",
        "stuffer/*.c",
        "tls/*.c",
        "tls/extensions/*.c",
        "utils/*.c",
        "pq-crypto/*.c",
        "pq-crypto/kyber_r3/*.c",
    ]),
    hdrs = glob([
        "api/*.h",
        "crypto/*.h",
        "error/*.h",
        "stuffer/*.h",
        "tls/*.h",
        "tls/extensions/*.h",
        "utils/*.h",
        "pq-crypto/*.h",
        "pq-crypto/kyber_r3/*.h",
    ]),
    copts = [
        "-DS2N_NO_PQ_ASM",
    ],
    includes = [
        "api/",
    ],
    linkopts = [
        "-lpthread",
        "-dl",
        # "-rt",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@boringssl//:crypto",
    ],
)
