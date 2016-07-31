#! /bin/bash

# Defines
version=0.0.8
release=8
platform=x86_64

# Create rpmbuild directories
rm -rf rpmbuild
mkdir rpmbuild rpmbuild/BUILD rpmbuild/BUILDROOT rpmbuild/RPMS rpmbuild/SOURCES rpmbuild/SPECS rpmbuild/SRPMS

# Create an archive of the project
tar czf cdevstudio.tar.gz ../../../cdevstudio/
tar xf cdevstudio.tar.gz
mv cdevstudio cdevstudio-${version}
tar czf cdevstudio-${version}.tar.gz cdevstudio-${version}/

# Move the renamed archive to the rpmbuild/SOURCES directory
mv cdevstudio-${version}.tar.gz rpmbuild/SOURCES/cdevstudio-${version}.tar.gz

# Create package
rpmbuild --define "%_topdir $(pwd)/rpmbuild" -ba cdevstudio.spec

# Copy rpm
mv rpmbuild/RPMS/${platform}/cdevstudio-${version}-${release}.${platform}.rpm cdevstudio-${version}-${release}.${platform}.rpm

# Cleanup
rm -rf rpmbuild
rm -rf cdevstudio-${version}
rm cdevstudio.tar.gz
