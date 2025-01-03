// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#include <aws/core/Aws.h>
#include <aws/core/auth/AWSCredentials.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>

#include <fstream>
#include <iostream>

#include "s3_examples.h"

/**
 * Before running this C++ code example, set up your development environment, including your credentials.
 *
 * For more information, see the following documentation topic:
 *
 * https://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/getting-started.html
 *
 * Purpose
 *
 * Demonstrates using the AWS SDK for C++ to list the buckets in the current account.
 *
 */

//! Routine which demonstrates listing the buckets in the current account.
/*!
  \param clientConfig: Aws client configuration.
  \return bool: Function succeeded.
*/

// snippet-start:[s3.cpp.list_buckets.code]
bool AwsDoc::S3::listBuckets(const Aws::S3::S3ClientConfiguration& clientConfig) {
  Aws::S3::S3Client client(clientConfig);

  auto outcome = client.ListBuckets();

  bool result = true;
  if (!outcome.IsSuccess()) {
    std::cerr << "Failed with error: " << outcome.GetError() << std::endl;
    result = false;
  } else {
    std::cout << "Found " << outcome.GetResult().GetBuckets().size() << " buckets\n";
    for (auto&& b : outcome.GetResult().GetBuckets()) {
      std::cout << b.GetName() << std::endl;
    }
  }

  return result;
}
// snippet-end:[s3.cpp.list_buckets.code]

/*
 *
 *  main function
 *
 */

int main() {
  // The Aws::SDKOptions struct contains SDK configuration options.
  // An instance of Aws::SDKOptions is passed to the Aws::InitAPI and
  // Aws::ShutdownAPI methods. The same instance should be sent to both methods.
  Aws::SDKOptions options;

  // The AWS SDK for C++ must be initialized by calling Aws::InitAPI.
  InitAPI(options);

  {
    Aws::S3::S3ClientConfiguration clientConfig;
    // Set credentials path
    const char* credentialsPath = std::getenv("AWS_SHARED_CREDENTIALS_FILE");
    const char* configPath = std::getenv("AWS_CONFIG_FILE");

    // Debug logging
    std::cout << "AWS_SHARED_CREDENTIALS_FILE: " << (credentialsPath ? credentialsPath : "not set") << std::endl;
    std::cout << "AWS_CONFIG_FILE: " << (configPath ? configPath : "not set") << std::endl;

    if (credentialsPath != nullptr) {
      clientConfig.profileName = "default";  // Use the default profile from credentials file
      std::cout << "Using profile: " << clientConfig.profileName << std::endl;
    } else {
      std::cout << "No credentials path found!" << std::endl;
    }

    // Add timeouts to prevent hanging
    clientConfig.connectTimeoutMs = 5000;   // 5 seconds connection timeout
    clientConfig.requestTimeoutMs = 10000;  // 10 seconds request timeout

    // SSL Configuration
    // TODO: Figure out why we get CURL 60 errors using SSL
    clientConfig.verifySSL = false;

    // After checking credentials file, add config file check
    if (configPath != nullptr) {
      std::cout << "Checking if config file exists..." << std::endl;
      std::ifstream configFile(configPath);
      if (configFile.good()) {
        std::cout << "Config file found and readable." << std::endl;
        std::string line;
        while (std::getline(configFile, line)) {
          if (line.find("region") != std::string::npos) {
            size_t pos = line.find("=");
            if (pos != std::string::npos) {
              clientConfig.region = Aws::String(line.substr(pos + 1));
              // Trim whitespace
              clientConfig.region = Aws::Utils::StringUtils::Trim(clientConfig.region.c_str());
              std::cout << "Using region from config: " << clientConfig.region << std::endl;
            }
          }
        }
        configFile.close();
      } else {
        std::cout << "Cannot open config file at: " << configPath << std::endl;
      }
    }

    std::cout << "Creating S3 client..." << std::endl;
    Aws::S3::S3Client client(clientConfig);

    // Verify credentials are loaded
    auto credentialsProvider = Aws::MakeShared<Aws::Auth::ProfileConfigFileAWSCredentialsProvider>(
        "CredentialsProvider", "default");  // Pass "default" as const char* directly

    if (credentialsProvider) {
      std::cout << "Checking if credentials file exists..." << std::endl;
      std::ifstream credsFile(credentialsPath);
      if (!credsFile.good()) {
        std::cout << "Cannot open credentials file at: " << credentialsPath << std::endl;
        // Try the default location
        std::ifstream defaultCredsFile("/root/.aws/credentials");
        if (defaultCredsFile.good()) {
          std::cout << "Found credentials at default location /root/.aws/credentials" << std::endl;
          std::string line;
          while (std::getline(defaultCredsFile, line)) {
            std::cout << "Content: " << line << std::endl;
          }
          defaultCredsFile.close();
        } else {
          std::cout << "Also cannot find credentials at default location" << std::endl;
        }
      } else {
        std::cout << "Credentials file found and readable." << std::endl;
        credsFile.close();
      }

      auto creds = credentialsProvider->GetAWSCredentials();
      if (creds.GetAWSAccessKeyId().empty()) {
        std::cout << "Failed to load credentials!" << std::endl;
        std::cout << "Profile name being used: " << clientConfig.profileName << std::endl;
      } else {
        std::cout << "Credentials loaded successfully. Access key ID: " << creds.GetAWSAccessKeyId().substr(0, 5)
                  << "..." << std::endl;
      }
    } else {
      std::cout << "Failed to create credentials provider!" << std::endl;
    }

    std::cout << "Attempting to list buckets..." << std::endl;
    AwsDoc::S3::listBuckets(clientConfig);
  }

  // Before the application terminates, the SDK must be shut down.
  ShutdownAPI(options);
  return 0;
}
