<p align=center>
  <img src="./resources/icon.png">
  <h1 align=center>CubeBase</h1>
  <p align=center>A simple all-in-one speed-cubing application.</p>
</p>


> [!NOTE]
> Please check out the Wikipedia [Speedcubing article](https://en.wikipedia.org/wiki/Speedcubing) and [cstimer.net](https://cstimer.net) if you are not familiar with the terms.

## Installation

Go to [releases](https://github.com/reo6/CubeBase/releases) for Windows and Linux builds.

## Building

Build dependencies:

- GCC/Clang
- make
- raylib

#### Linux

Building:

```
make build
```

You can find the executable at ``build/cubebase``.

#### Windows

You can use the [``./build-windows-mingw.sh``](./build-windows-mingw.sh) script to build for windows. Follow the instructions provided in script.

### Keybindings

| Key              	| Function                                            	|
|------------------	|-----------------------------------------------------	|
| <kbd>Space</kbd> 	| Hold and release to start the timer, press to stop. 	|
| <kbd>S</kbd>     	| Reset the scramble                                  	|
| <kbd>TAB</kbd>   	| Browse color schemes                                	|
