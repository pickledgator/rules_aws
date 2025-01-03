#!/bin/bash

set -e
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

cd "$SCRIPT_DIR"

echo "Building rules_aws_example for linux/arm64"
DOCKER_BUILDKIT=1 docker buildx build --platform linux/arm64 -t "rules_aws_example:arm64" .

echo "Building rules_aws_example for linux/amd64"
DOCKER_BUILDKIT=1 docker buildx build --platform linux/amd64 -t "rules_aws_example:amd64" .
