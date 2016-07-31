#! /bin/bash

# Create archive and unpack it
tar -czf cdevstudio.tar.gz ../../../cdevstudio/
tar -xf cdevstudio.tar.gz

# Change into cdevstudio directory and create a build directory
cd cdevstudio
mkdir -p build
cd build
rm -rf *

# Run cmake
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr

# Build and install
make
sudo make install

# Cleanup
cd ../..
rm -rf cdevstudio
rm cdevstudio.tar.gz
