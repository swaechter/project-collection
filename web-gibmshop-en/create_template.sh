#!/bin/bash

# Get the shell script directory
DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# Change the directory
cd $DIR

# Zip the src directory
cd src/
zip -r gibm-notebook-shop.zip *

# Copy the template
mv gibm-notebook-shop.zip ../template/
