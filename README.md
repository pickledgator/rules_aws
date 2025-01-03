# AWS C++ API Example

This project demonstrates using the AWS SDK for C++ to list S3 buckets, built with Bazel.

## Prerequisites

- Docker
- AWS credentials (access key and secret key)
- AWS config with region settings

## Setup

1. Create your AWS credentials file in the project root as `credentials`:
```ini
[default]
aws_access_key_id = YOUR_ACCESS_KEY_ID
aws_secret_access_key = YOUR_SECRET_KEY
```

2. Create your AWS config file in the project root as `config`:
```ini
[default]
region = us-west-2
```

## Building the Container

Build the container, supports both arm64 & amd64:
```bash
./docker/build.sh
```

## Running the Example

1. Start the development shell:
```bash
./docker/shell.sh
```

2. Inside the container, build and run the example:
```bash
bazel run //:example
```

## Example Output
```
AWS_SHARED_CREDENTIALS_FILE: /root/.aws/credentials
AWS_CONFIG_FILE: /root/.aws/config
Using profile: default
Checking if config file exists...
Config file found and readable.
Using region from config: us-west-2
Creating S3 client...
Checking if credentials file exists...
Credentials file found and readable.
Credentials loaded successfully. Access key ID: AKIAX...
Attempting to list buckets...
Found 82 buckets
...
```

## Project Structure

- `example.cpp`: Main application code
- `docker/`: Contains Dockerfile and shell scripts for the build environment
- `third_party/`: Bazel BUILD files for dependencies
- `BUILD.bazel`: Main build configuration
- `WORKSPACE`: Bazel workspace configuration

## Notes

- SSL verification is currently disabled to avoid certificate issues
- Credentials are mounted read-only into the container
- The example uses the default AWS profile
- Supports at least some of the common AWS services (DynamoDB, S3, KMS, Greengrass, etc.)
- Other AWS services can be added by adding the appropriate Bazel BUILD files to `third_party/`. Most of the services can be found in the [AWS SDK for C++](https://github.com/aws/aws-sdk-cpp) repository. Specifically, see https://github.com/aws/aws-sdk-cpp/tree/main/generated/src
- The `example.cpp` file is a simple example of how to use the AWS SDK for C++. It is not meant to be a comprehensive example of all the AWS SDK for C++ features.
