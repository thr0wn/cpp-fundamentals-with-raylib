[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

## Classy clash
Game developed at course "Udemy: Cpp fundamentals".

### Build
```shell
cmake -DCXX=g++ -S . -B ./build && cmake --build build
```

### Debug
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/classy_clash/exe
```

### Build tests
```shell
cmake -S . -B build && cmake --build build --target unit-tests && ./build/tests/unit-tests
```

### Run
```shell
./build/classy_clash/exe
```

### Watch with nodemon
```shell
npx nodemon --exec "cmake -S . -B build && cmake --build build && ./build/classy_clash/exe" --watch src -e cpp,hpp,txt
```
