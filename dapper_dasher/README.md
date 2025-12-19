[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)
<img width="724" height="435" alt="image" src="https://github.com/user-attachments/assets/d8aac96f-7f6a-4147-8a65-35548bead835" />

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
