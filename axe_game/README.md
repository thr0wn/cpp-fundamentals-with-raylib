[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

## Axe game
Game developed at course "Udemy: Cpp fundamentals".

### Build
```shell
cmake -DCXX=g++ -S . -B ./build && cmake --build build
```

### Debug
```shell
CXX=g++ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/axe_game/axe_game
```

### Run
```shell
./build/axe_game/axe_game
```
