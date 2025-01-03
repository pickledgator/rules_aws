FROM ubuntu:20.04

ARG TARGETARCH
ARG TARGETPLATFORM

RUN echo "I'm building for $TARGETARCH, $TARGETPLATFORM"

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
  curl \
  build-essential \
  shellcheck \
  gdb \
  rsync \
  cmake \
  pkg-config \
  gcc-10 \
  g++-10 \
  ca-certificates \
  gnupg \
  lsb-release \
  unzip \
  wget \
  libssl-dev \
  && update-ca-certificates \
  && rm -rf /var/lib/apt/lists/*

# Use GCC 10
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 100

# Install bazel
RUN curl -L https://github.com/bazelbuild/bazelisk/releases/download/v1.10.1/bazelisk-linux-$TARGETARCH -O && \
  mv bazelisk-linux-$TARGETARCH /usr/local/bin/bazel && \
  chmod +x /usr/local/bin/bazel

# AWS CLI Install
# This isn't really used for anything with bazel, but an example of how to install the CLI, if desired
RUN curl "https://awscli.amazonaws.com/awscli-exe-linux-$(uname -m).zip" -o "awscliv2.zip" && \
  unzip awscliv2.zip && \
  ./aws/install && \
  rm awscliv2.zip

# Create workspace directory and copy entrypoint
RUN mkdir -p /workspace
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod 755 /usr/local/bin/entrypoint.sh

WORKDIR /workspace
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["/bin/bash"]
