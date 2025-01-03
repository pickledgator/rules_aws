load("@rules_aws//tools:template_rule.bzl", "template_rule")

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "aws-cpp-sdk-core",
    srcs = glob([
        "src/aws-cpp-sdk-core/source/*.cpp",
        "src/aws-cpp-sdk-core/source/external/**/*.cpp",
        "src/aws-cpp-sdk-core/source/auth/**/*.cpp",
        "src/aws-cpp-sdk-core/source/client/**/*.cpp",
        "src/aws-cpp-sdk-core/source/config/**/*.cpp",
        "src/aws-cpp-sdk-core/source/internal/**/*.cpp",
        "src/aws-cpp-sdk-core/source/endpoint/**/*.cpp",
        "src/aws-cpp-sdk-core/source/aws/model/*.cpp",
        "src/aws-cpp-sdk-core/source/http/*.cpp",
        "src/aws-cpp-sdk-core/source/http/curl/*.cpp",
        "src/aws-cpp-sdk-core/source/http/standard/*.cpp",
        "src/aws-cpp-sdk-core/source/monitoring/**/*.cpp",
        "src/aws-cpp-sdk-core/source/net/linux-shared/*.cpp",
        "src/aws-cpp-sdk-core/source/platform/linux-shared/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/event/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/base64/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/json/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/logging/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/memory/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/stream/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/threading/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/xml/**/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/crypto/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/crypto/openssl/*.cpp",
        # "src/aws-cpp-sdk-core/source/utils/crypto/bcrypt/*.cpp",
        "src/aws-cpp-sdk-core/source/utils/crypto/factory/**/*.cpp",
    ]),
    hdrs = glob(
        [
            "src/aws-cpp-sdk-core/include/aws/core/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/auth/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/auth/signer/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/auth/signer-provider/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/auth/bearer-token-provider/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/client/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/internal/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/endpoint/**/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/net/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/http/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/http/standard/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/config/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/config/defaults/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/monitoring/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/platform/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/event/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/base64/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/crypto/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/crypto/openssl/*.h",
            # "src/aws-cpp-sdk-core/include/aws/core/utils/crypto/bcrypt/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/json/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/threading/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/xml/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/memory/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/logging/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/ratelimiter/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/utils/stream/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/external/cjson/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/external/tinyxml2/*.h",
            "src/aws-cpp-sdk-core/include/aws/core/http/curl/*.h",
        ],
        exclude = [
            "src/aws-cpp-sdk-core/include/aws/core/utils/commoncrypto/CryptoImpl.h",
            "src/aws-cpp-sdk-core/include/aws/core/external/CommonCryptorSPI.h",
            # For some reason the default VersionConfig.h occasionally throws build errors
            # so we re-generate it below with the template_rule
            "src/aws-cpp-sdk-core/include/aws/core/VersionConfig.h",
        ],
    ) + [
        "src/aws-cpp-sdk-core/include/aws/core/SDKConfig.h",
        "src/aws-cpp-sdk-core/include/aws/core/VersionConfig.h",
    ],
    defines = [
        "ENABLE_CURL_CLIENT",
        "CHECK_CURL_HAS_H2",
        "CHECK_CURL_HAS_TLS_PROXY",
        # "ENABLE_BCRYPT_ENCRYPTION",
        "ENABLE_OPENSSL_ENCRYPTION",
        "OPENSSL_IS_BORINGSSL",
        "PLATFORM_LINUX",
        "USE_AWS_MEMORY_MANAGEMENT=0",
    ],
    includes = [
        "src/aws-cpp-sdk-core/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@aws-c-common",
        "@aws-c-event-stream",
        "@aws-checksums",
        "@aws-crt-cpp",
        "@boringssl//:crypto",
        "@boringssl//:ssl",
        "@curl",
    ],
)

cc_library(
    name = "aws-cpp-sdk-dynamodb",
    srcs = glob([
        "generated/src/aws-cpp-sdk-dynamodb/source/**/*.cpp",
    ]),
    hdrs = glob([
        "generated/src/aws-cpp-sdk-dynamodb/include/**/*.h",
    ]),
    includes = [
        "generated/src/aws-cpp-sdk-dynamodb/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

cc_library(
    name = "aws-cpp-sdk-s3",
    srcs = glob([
        "generated/src/aws-cpp-sdk-s3/source/**/*.cpp",
    ]),
    hdrs = glob([
        "generated/src/aws-cpp-sdk-s3/include/**/*.h",
    ]),
    includes = [
        "generated/src/aws-cpp-sdk-s3/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

cc_library(
    name = "aws-cpp-sdk-kms",
    srcs = glob([
        "generated/src/aws-cpp-sdk-kms/source/**/*.cpp",
    ]),
    hdrs = glob([
        "generated/src/aws-cpp-sdk-kms/include/**/*.h",
    ]),
    includes = [
        "generated/src/aws-cpp-sdk-kms/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

cc_library(
    name = "aws-cpp-sdk-transfer",
    srcs = glob([
        "src/aws-cpp-sdk-transfer/source/**/*.cpp",
    ]),
    hdrs = glob([
        "src/aws-cpp-sdk-transfer/include/**/*.h",
    ]),
    includes = [
        "src/aws-cpp-sdk-transfer/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

cc_library(
    name = "aws-cpp-sdk-appsync",
    srcs = glob([
        "generated/src/aws-cpp-sdk-appsync/source/**/*.cpp",
    ]),
    hdrs = glob([
        "generated/src/aws-cpp-sdk-appsync/include/**/*.h",
    ]),
    includes = [
        "generated/src/aws-cpp-sdk-appsync/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

cc_library(
    name = "aws-cpp-sdk-greengrassv2",
    srcs = glob([
        "generated/src/aws-cpp-sdk-greengrassv2/source/**/*.cpp",
    ]),
    hdrs = glob([
        "generated/src/aws-cpp-sdk-greengrassv2/include/**/*.h",
    ]),
    includes = [
        "generated/src/aws-cpp-sdk-greengrassv2/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":aws-cpp-sdk-core",
    ],
)

template_rule(
    name = "SDKConfig_h",
    src = "src/aws-cpp-sdk-core/include/aws/core/SDKConfig.h.in",
    out = "src/aws-cpp-sdk-core/include/aws/core/SDKConfig.h",
    substitutions = {
        "cmakedefine": "undef",
    },
)

template_rule(
    name = "VersionConfig_h",
    src = "src/aws-cpp-sdk-core/include/aws/core/VersionConfig.h.in",
    out = "src/aws-cpp-sdk-core/include/aws/core/VersionConfig.h",
    substitutions = {
        # Note that this version must match the version in WORKSPACE
        "@AWSSDK_VERSION_STRING@": "1.11.55",
        "@AWSSDK_VERSION_MAJOR@": "1",
        "@AWSSDK_VERSION_MINOR@": "11",
        "@AWSSDK_VERSION_PATCH@": "55",
    },
)
