# Cub3D

The main goal of this this project is to create a raycaster using techniques inspired by `Wolfenstein 3D`.<br>
✅ Final grade: 105/100<br>
(Old project completed in May 2021, project details were changed in July 2021)

## Objective

In this 42 project we are asked to extract information from a .cub file and use that to draw a 3D perspective of a 2D maze on the screen using raycasting principles.

Example of a valid cub file's information:
```
R 1920 1080

NO ./textures/greystone.xpm
SO ./textures/purplestone.xpm
WE ./textures/redbrick.xpm
EA ./textures/wood.xpm

S ./textures/sprite.xpm
F 77,92,53
C 163,208,230

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000002000001
		1001000000000000000002001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
This project had several challenges

    > Finding the right way to extract the cub information.
    > Parsing the .cub file correctly.
    > Using and understanding the minilibx drawing tool.
    > Understanding raycasting and the DDA algorithm.
    > Creating the bmp screenshot file.

Link to [`minilibx manual`](https://harm-smits.github.io/42docs/libs/minilibx)
## Showcase

Controls:<br>
> WASD and Left/Right Arrow Keys for movement and rotating the camera.

Bonuses:<br>
> Minimap with player FOV<br>
> Wall and sprite collision<br>
> Custom textures and sprites

Personal Bonus:<br>
Trippy mode using ARGB/TRGB manipulation<br>(Up and Down Arrow Key to toggle)<br><br>
![trip_mode_gif](cub3D.gif)
