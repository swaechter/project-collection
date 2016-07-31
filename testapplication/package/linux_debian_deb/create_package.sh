#! /bin/bash

email=waechter.simon@gmail.com
version=0.1.0

./clean_package.sh

tar -czf testapplication_${version}.orig.tar.gz ../../../testapplication/
tar -xf testapplication_${version}.orig.tar.gz

mv testapplication testapplication-${version}

cp -R debian testapplication-${version}
cd testapplication-${version}

dh_make -s -e ${email} -f ../testapplication_${version}.orig.tar.gz
debuild -us -uc

cd ..

rm -rf testapplication-*
rm *.dsc
rm *.tar.gz
rm *.build
rm *.changes