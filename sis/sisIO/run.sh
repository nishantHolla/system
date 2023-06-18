
#!/bin/bash

cmake -B build -S .
cd build
make
cd ..
mv -f build/libsisIO.a test
cd test
./buildTest.sh
