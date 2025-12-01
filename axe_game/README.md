[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)
<img width="724" height="435" alt="image" src="https://github.com/user-attachments/assets/d8aac96f-7f6a-4147-8a65-35548bead835" />

## Axe game
Game developed at course "Udemy: Cpp fundamentals". Use "A" and "D" to move the circle.

### Build
```shell
cmake -DCXX=g++ -S . -B ./build && cmake --build build
```

### Debug
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/axe_game/axe_game
```

### Run
```shell
./build/axe_game/axe_game
```

### Watch with nodemon
```shell
npx nodemon --exec "cmake -S . -B build && cmake --build build && ./build/axe_game/axe_game" --watch src -e cpp,hpp,txt
```
