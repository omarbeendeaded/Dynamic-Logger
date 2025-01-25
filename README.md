# Dynamic Logger
A dynamically configured logging library. It has 5 levels that can be set using an integer sent with the real-time signal `SIGRTMIN`. 

### Usage
To initialize the logger call the following function at the top of the code:
```
initLogger();
```
The library defines 4 functions representing a different level each in this order:
```
1 - LOG_ERROR
2 - LOG_WARNING
3 - LOG_INFO
4 - LOG_DEBUG
```
The output is display or ommitted based on the current level.

Using the level setting program the user sends a signal as follows:
```
./levelSetter [PID] [level]
```
The levels are `disable`, `error`, `warning`, `info`, `debug`.
### Compilation
To compile the library with your program:
```
gcc -o logTest logTest.c logger.c
```
To compile the level setter:
```
gcc -o levelSetter levelSetter.c
```

