# C++ CI/CD Learning Project

A hands-on project for learning CI/CD with C++.

## What's included

| Tool | Purpose |
|------|---------|
| CMake + Ninja | Build system |
| GoogleTest | Unit testing |
| clang-format | Code formatting |
| clang-tidy | Static analysis |
| Docker | Multi-stage container build |
| GitHub Actions | CI/CD pipeline |

## CI Pipeline

Every push/PR runs three jobs in sequence:

```
lint ──┐
       ├──▶ docker build
test ──┘
```

1. **Lint** — checks formatting with `clang-format` and static analysis with `clang-tidy`
2. **Build & Test** — compiles with CMake and runs GoogleTest suite
3. **Docker** — builds a minimal runtime image (only runs if lint + tests pass)

## Local development

```bash
# Build
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure

# Run the app
./build/app

# Check formatting
find src include tests -name "*.cpp" -o -name "*.h" | xargs clang-format --dry-run --Werror

# Build Docker image
docker build -t cpp-cicd-learning .
docker run --rm cpp-cicd-learning
```
