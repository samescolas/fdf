# fdf

The goal of this project was to create a program to read a map of integers representing heights of coordinates
and display a 3d wireframe of the map using nothing more than pixel_put to draw to the screen.

## Use:
run `make` to compile and `./fdf ./maps/(CHOOSE MAP)` to start

![fdf screenshot](/example.png)

## Controls

|Key|Action|
|-----|-------|
|w|Translate up|
|a|Translate left|
|s|Translate down|
|d|Translate right|
|-|Zoom out|
|+|Zoom in|
|[|Decrease z values|
|]|Increase z values|
|left arrow|Rotate left about x|
|right arrow|Rotate right about x|
|up arrow|Rotate up around y|
|down arrow|Rotate down around y|
|o|Rotate left around z|
|p|Rotate right around z|
|r|Increase or decrease amount of red|
|g|Increase or decrease amount of green|
|b|Increase or decrease amount of blue|
