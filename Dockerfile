# cub3D — Linux build + valgrind environment
# Build:  docker build -t cub3d .
# Shell:  docker run -it --rm cub3d
# Leaks:  docker run -it --rm cub3d make leak
# GUI (optional, needs X server on host): see README notes at bottom.

FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# build tools + X11 dev headers (needed to compile minilibx) + valgrind + xvfb
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        gcc \
        make \
        xorg \
        libx11-dev \
        libxext-dev \
        libbsd-dev \
        valgrind \
        xvfb \
        x11-apps \
        xdotool \
        imagemagick \
        python3 \
        python3-pip \
    && rm -rf /var/lib/apt/lists/*

# 42 norm checker
RUN pip3 install --no-cache-dir norminette

WORKDIR /cub3d
COPY . .

# minilibx ships a ./configure that its Makefile calls — make it executable,
# then build everything (minilibx -> libft -> cub3D) via our Makefile.
RUN chmod +x minilibx/configure && make re

# default: interactive shell so you can run `make leak`, `./cub3D maps/...`, etc.
CMD ["/bin/bash"]
