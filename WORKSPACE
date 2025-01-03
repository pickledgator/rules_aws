workspace(name = "rules_aws")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "curl",
    build_file = "//third_party:curl.BUILD",
    sha256 = "910cc5fe279dc36e2cca534172c94364cf3fcf7d6494ba56e6c61a390881ddce",
    strip_prefix = "curl-7.82.0",
    urls = [
        "https://curl.se/download/curl-7.82.0.tar.gz",
    ],
)

http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "8c05641b9f91cbc92f51cc4a5b3a226788d7a63f20af4ca7aaca50d92cc94a0d",
    strip_prefix = "grpc-1.44.0",
    urls = [
        "https://github.com/grpc/grpc/archive/v1.44.0.tar.gz",
    ],
)

# This next line pulls dependencies including protobuf as @com_google_protobuf
# We use this version to explicitly ensure that gRPC stays in sync with protobuf
# Other deps like gtest don't matter as much
# Currently utilizes protobuf commit 19fb89416f3fdc2d6668f3738f444885575285bc from Jan 13, 2021
# Also adds: zlib, gtest, boringssl, benchmark, libuv
# We really only need boringssl here, but I'm too lazy to figure out what version was used by grpc
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

# AWS SDK Packages
# Note that if you change this version, you must update third_party/aws.BUILD
http_archive(
    name = "aws",
    build_file = "//third_party:aws.BUILD",
    sha256 = "0816ab40c6fc373351b67ae3699777f09f35e1ad1a71d143b48e319db686f37b",
    strip_prefix = "aws-sdk-cpp-1.11.55",
    urls = [
        "https://github.com/aws/aws-sdk-cpp/archive/refs/tags/1.11.55.tar.gz",
    ],
)

http_archive(
    name = "aws-c-common",
    build_file = "//third_party:aws-c-common.BUILD",
    sha256 = "2d31b06f5f99ccdd88003e7cbdbac33e0802b4761136fe9589bf917f06b2314b",
    strip_prefix = "aws-c-common-0.8.15",
    urls = [
        "https://github.com/awslabs/aws-c-common/archive/refs/tags/v0.8.15.tar.gz",
    ],
)

http_archive(
    name = "aws-c-event-stream",
    build_file = "//third_party:aws-c-event-stream.BUILD",
    sha256 = "a1384c1f63c82a0a0bc64c3e1bc2a672c75614940b71418d96de9e057e31aafd",
    strip_prefix = "aws-c-event-stream-0.2.20",
    urls = [
        "https://github.com/awslabs/aws-c-event-stream/archive/refs/tags/v0.2.20.tar.gz",
    ],
)

http_archive(
    name = "aws-checksums",
    build_file = "//third_party:aws-checksums.BUILD",
    sha256 = "0f897686f1963253c5069a0e495b85c31635ba146cd3ac38cc2ea31eaf54694d",
    strip_prefix = "aws-checksums-0.1.13",
    urls = [
        "https://github.com/awslabs/aws-checksums/archive/refs/tags/v0.1.13.tar.gz",
    ],
)

http_archive(
    name = "aws-crt-cpp",
    build_file = "//third_party:aws-crt-cpp.BUILD",
    sha256 = "24a6be93d663d0cd2c5811865d488d30154f2738bea5b7836a5a8c1f01cb8457",
    strip_prefix = "aws-crt-cpp-0.19.8",
    urls = [
        "https://github.com/awslabs/aws-crt-cpp/archive/refs/tags/v0.19.8.tar.gz",
    ],
)

http_archive(
    name = "aws-c-io",
    build_file = "//third_party:aws-c-io.BUILD",
    sha256 = "0d54be16b10b60064e28cb2ab3f34383afcbf933c434cad3a28159e75a4c7d74",
    strip_prefix = "aws-c-io-0.13.19",
    urls = [
        "https://github.com/awslabs/aws-c-io/archive/refs/tags/v0.13.19.tar.gz",
    ],
)

http_archive(
    name = "aws-c-mqtt",
    build_file = "//third_party:aws-c-mqtt.BUILD",
    sha256 = "bbd07535b50b79a4ee1cf07d2713d4046181c676242f1533ec1eab14be07027a",
    strip_prefix = "aws-c-mqtt-0.8.8",
    urls = [
        "https://github.com/awslabs/aws-c-mqtt/archive/refs/tags/v0.8.8.tar.gz",
    ],
)

http_archive(
    name = "aws-c-auth",
    build_file = "//third_party:aws-c-auth.BUILD",
    sha256 = "8049a294198fd9e4ec782011c97e362ad62b5159d4ec4a7d6f478118d06d32fe",
    strip_prefix = "aws-c-auth-0.6.26",
    urls = [
        "https://github.com/awslabs/aws-c-auth/archive/refs/tags/v0.6.26.tar.gz",
    ],
)

http_archive(
    name = "aws-c-http",
    build_file = "//third_party:aws-c-http.BUILD",
    sha256 = "e0ed628372ab022ed311442f87629bb551acebea3900bf9b571a4da94a30905a",
    strip_prefix = "aws-c-http-0.7.6",
    urls = [
        "https://github.com/awslabs/aws-c-http/archive/refs/tags/v0.7.6.tar.gz",
    ],
)

http_archive(
    name = "aws-c-sdkutils",
    build_file = "//third_party:aws-c-sdkutils.BUILD",
    sha256 = "f21d770e6a41e82e658a92607a1df3c13bf905071843b8d6dfaaefc784102cd6",
    strip_prefix = "aws-c-sdkutils-0.1.8",
    urls = [
        "https://github.com/awslabs/aws-c-sdkutils/archive/refs/tags/v0.1.8.tar.gz",
    ],
)

http_archive(
    name = "aws-c-compression",
    build_file = "//third_party:aws-c-compression.BUILD",
    sha256 = "11d58a229e2961b2b36493155a981dea2c8a0bc0d113b0073deb8c3189cfa04e",
    strip_prefix = "aws-c-compression-0.2.15",
    urls = [
        "https://github.com/awslabs/aws-c-compression/archive/refs/tags/v0.2.15.tar.gz",
    ],
)

http_archive(
    name = "aws-c-cal",
    build_file = "//third_party:aws-c-cal.BUILD",
    sha256 = "23452ab7960c480f1ec0a96ac55bde32d7d27c4a664baeadc248923b19c12086",
    strip_prefix = "aws-c-cal-0.5.19",
    urls = [
        "https://github.com/awslabs/aws-c-cal/archive/refs/tags/v0.5.19.tar.gz",
    ],
)

http_archive(
    name = "aws-c-s3",
    build_file = "//third_party:aws-c-s3.BUILD",
    sha256 = "7b8487a9a13df885cbc4416b6b318ade75993988e8be0de91011316d2225272e",
    strip_prefix = "aws-c-s3-0.2.8",
    urls = [
        "https://github.com/awslabs/aws-c-s3/archive/refs/tags/v0.2.8.tar.gz",
    ],
)

http_archive(
    name = "aws-s2n",
    build_file = "//third_party:aws-s2n.BUILD",
    sha256 = "9d05578e881005db18ab979780b6af6c6099bae60bb6081b57e21c5e0615771d",
    strip_prefix = "s2n-tls-1.3.20",
    urls = [
        "https://github.com/aws/s2n-tls/archive/refs/tags/v1.3.20.tar.gz",
    ],
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-0.0.1",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/refs/tags/0.0.1.tar.gz"],
)

load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies")

rules_cc_dependencies()
