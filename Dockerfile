FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

# Install required dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    unzip \
    && rm -rf /var/lib/apt/lists/* 

# Install Google Test
WORKDIR /usr/src/gtest
RUN git clone https://github.com/google/googletest.git && \
    cd googletest && \
    cmake . && \
    make && \
    make install

# Set working directory for your project
WORKDIR /usr/src/test

# Copy your project files into the container
COPY . .

# Build the project
RUN mkdir -p build && cd build && \
    cmake .. && \
    cmake --build .

# Run the tests
CMD ["ctest", "--output-on-failure", "--test-dir", "build"]
