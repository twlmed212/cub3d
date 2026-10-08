*This project has been created as part of the 42 curriculum by mtawil, abmoudni.*

# cub3D: Mok3ab3D

## Description

**cub3D** is a first-person 3D maze renderer written in C, inspired by **Wolfenstein 3D** (id Software, 1992).
The goal is to understand **ray-casting**: how a game can draw a 3D-looking world from a simple 2D grid, using math instead of a 3D engine.

The program reads a scene file (`.cub`) that describes the wall textures, the floor and ceiling colors, and the map. It then opens a window where you can walk through the maze. Rendering is done with the **MiniLibX** graphics library.

### Features

- Real-time 3D view of the maze from a first-person point of view
- A different wall texture for each direction: **North, South, East, West**
- Separate colors for the **floor** and the **ceiling**
- Smooth movement and rotation, with wall collision
- Full validation of the `.cub` file: textures, colors, characters, player position, and a map closed by walls. Any problem prints `Error` followed by a clear message.
- Clean exit with `ESC` or the window's close button, with all memory freed

### How it works

The map is a 2D grid. For every vertical column of the screen, the program:

1. **Casts a ray** from the player's position in the direction of that column. The field of view is about 66°.
2. **Steps through the grid with the DDA algorithm** (Digital Differential Analysis), checking one grid line at a time until the ray hits a wall.
3. **Computes the distance to the wall.** It uses the perpendicular distance, which avoids the "fish-eye" effect.
4. **Draws a vertical stripe.** The closer the wall, the taller the stripe. The right column of the wall texture is chosen depending on where the ray hit and which side of the wall it hit.
5. Fills the rest of the column with the ceiling color above and the floor color below.

Each frame is drawn into an off-screen MiniLibX image, then pushed to the window in one step, so the picture doesn't flicker.

## Instructions

### Requirements

cub3D uses the Linux (X11) version of MiniLibX, which is included in the repository.

- `cc`, `make`
- X11 development libraries
  - Debian / Ubuntu: `sudo apt install libx11-dev libxext-dev zlib1g-dev`

### Build and run

```bash
git clone https://github.com/twlmed212/cub3d.git
cd cub3d
make
./cub3D maps/a1.cub
```

Other `Makefile` rules: `make clean`, `make fclean`, `make re`.

### Controls

| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Move left / right |
| `←` / `→` | Look left / right |
| `ESC` | Quit |
| Window close button | Quit |

### Scene file (`.cub`)

```
NO xpm/ma_texture1.xpm
SO xpm/ma_texture2.xpm
WE xpm/ma_texture3.xpm
EA xpm/ma_texture4.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

- `NO`, `SO`, `WE`, `EA`: paths to the wall textures (`.xpm`)
- `F`, `C`: floor and ceiling colors in `R,G,B`, each value from 0 to 255
- Map characters:
  - `1` is a wall
  - `0` is empty space
  - `N`, `S`, `E`, `W` is the player's start position and direction
- The map must be the last element and must be fully closed by walls.

Example maps are in [`maps/`](maps).

### Project structure

```
cub3d/
├── Makefile
├── includes/cub3d.h      # Structures, constants, prototypes
├── src/
│   ├── main.c
│   ├── parsing/          # .cub file reading and validation
│   ├── engine/           # Init, ray-casting (DDA), drawing, textures, movement, key hooks
│   ├── utils/
│   └── cleaner/          # Memory and MiniLibX cleanup
├── maps/                 # Example scenes
├── xpm/                  # Wall textures
├── libft/                # Our own C library
├── get_next_line/        # Line-by-line file reading
└── minilibx/             # MiniLibX (Linux)
```

## Resources

### References

- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html): the classic explanation of DDA ray-casting
- [Ray-Casting Tutorial for Game Development](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) by F. Permadi
- [Digital Differential Analyzer (graphics algorithm)](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) on Wikipedia
- [MiniLibX documentation (42 Docs)](https://harm-smits.github.io/42docs/libs/minilibx)
- The MiniLibX man pages, included in [`minilibx/man/`](minilibx/man)

### AI usage

AI was used to help write and organize this README. The parsing, the ray-casting engine, and the rendering were designed and written by the authors, and every part was tested and reviewed between us.

## Authors

- **Mohamed Tawil** (`mtawil`): [@twlmed212](https://github.com/twlmed212)
- **Abdessamad Moudnibe** (`abmoudni`): [@abmoudni](https://github.com/abmoudni)
