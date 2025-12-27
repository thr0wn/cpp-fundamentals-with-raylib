[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

![gamelplay](https://github.com/user-attachments/assets/7e43affc-78b2-411a-9f99-e98e0138c67e)

## Dapper Dasher
Game developed at course "Udemy: Cpp fundamentals". Use "A" and "D" to move the circle.

### Build
```shell
cmake -DCXX=g++ -S . -B ./build && cmake --build build
```

### Debug
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/dapper_dasher/exe
```

### Build tests
```shell
cmake -S . -B build && cmake --build build --target unit-tests && ./build/tests/unit-tests
```

### Run
```shell
./build/dapper_dasher/exe
```

### Watch with nodemon
```shell
npx nodemon --exec "cmake -S . -B build && cmake --build build && ./build/dapper_dasher/exe" --watch src -e cpp,hpp,txt
```
