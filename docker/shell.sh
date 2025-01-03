#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

WORKSPACE_ROOT="$SCRIPT_DIR/.."
HOME_DIR="/workspace"
CACHE_DIR="$HOME/.cache" # Store bazel cache on host

# Architecture specific flags
# Add the right docker arg for display forwarding depending on the architecture.
HOST_ENV="$(uname -s)"
ARCHITECTURE="$(uname -m)"
case "${HOST_ENV}" in
    Linux*)
      # For linux systems, just expose the host network
      NETWORK="host"
    ;;
    Darwin*)
      NETWORK="docker_network"
      # If the network doesn't already exist, create it
      NETWORK_CHECK=$(docker network ls | grep $NETWORK || true)
      if [ -z "$NETWORK_CHECK" ]; then
        docker network create "$NETWORK"
      fi
    ;;
    CYGWIN*)    ;;
    MINGW*)     ;;
    *)
esac

# shellcheck disable=SC2086,SC2068
docker run --rm \
  --network="$NETWORK" \
  --ipc host \
  --pid host \
  -e AWS_CONFIG_FILE="/root/.aws/config" \
  -e AWS_SHARED_CREDENTIALS_FILE="/root/.aws/credentials" \
  -v "$WORKSPACE_ROOT/credentials:/root/.aws/credentials:ro" \
  -v "$WORKSPACE_ROOT/config:/root/.aws/config:ro" \
  -v "$WORKSPACE_ROOT:$HOME_DIR" \
  -v "$CACHE_DIR:/workspace/.cache":Z \
  -v "/var/run/docker.sock:/var/run/docker.sock" \
  -it \
  rules_aws_example:"$ARCHITECTURE" $@
