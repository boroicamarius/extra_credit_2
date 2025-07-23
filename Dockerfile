# Start the Dockerfile with a minimal and secure base image for C++
FROM debian:bullseye-slim AS build

# Set the environment to non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages: minimal set for building
# CMake, C++ compiler, and any dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    cmake \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the entire project to the working directory
COPY . .

# Run CMake and build the project
# Leverage CMakeLists.txt for building the project
RUN cmake . && make

# Start a new stage with only the necessary runtime environment
FROM debian:bullseye-slim AS runtime

# Set the environment to non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Install only the runtime dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    tini \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the built binaries from the build stage
COPY --from=build /app/c_env /usr/local/bin/c_env

# Expose the default port of the application if required

# Use Tini to ensure proper handling of process signals
ENTRYPOINT ["/usr/bin/tini", "--"]

# Default command to execute when the container starts
CMD ["/usr/local/bin/c_env"]