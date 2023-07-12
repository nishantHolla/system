
#!/bin/bash

cmake -S . -B build && \
cd build && \
make && \
mv ./sisCall ../output/ && \
cd ../output && \
./sisCall $@
