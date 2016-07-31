#! /bin/bash

# Defines
version=0.1.0
distribution=1.fc20
platform=x86_64

# Create rpmbuild directories
rm -rf rpmbuild
mkdir rpmbuild rpmbuild/BUILD rpmbuild/BUILDROOT rpmbuild/RPMS rpmbuild/SOURCES rpmbuild/SPECS rpmbuild/SRPMS

# Create an archive of the project
tar czf testapplication.tar.gz ../../../testapplication/
tar xf testapplication.tar.gz
mv testapplication testapplication-${version}
tar czf testapplication-${version}.tar.gz testapplication-${version}/

# Move the renamed archive to the rpmbuild/SOURCES directory
mv testapplication-${version}.tar.gz rpmbuild/SOURCES/testapplication-${version}.tar.gz

# Create package
rpmbuild --define "%_topdir $(pwd)/rpmbuild" -ba testapplication.spec

# Copy rpm
mv rpmbuild/RPMS/${platform}/testapplication-${version}-${distribution}.${platform}.rpm testapplication-${version}-1.${platform}.rpm

# Cleanup
rm -rf rpmbuild
rm -rf testapplication
rm -rf testapplication-${version}
rm testapplication.tar.gz