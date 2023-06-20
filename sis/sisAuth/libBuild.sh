
#!/bin/bash

cmake -S . -B build -DCMAKE_BUILD_TYPE=$1 && \
cd build && \
make && \
mv -f libsisAuth.a ./../output
