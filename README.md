<p align="center"> <img
 src="https://game.42sp.org.br/static/assets/achievements/libftm.png"> </p>

<p align="center"> <img src="https://img.shields.io/badge/OS-Linux-blue"
 alt="OS"> <img src="https://img.shields.io/badge/Language-C-orange.svg"
  alt="Language"> <img
  src="https://img.shields.io/badge/Grade-115%2F100-brightgreen.svg"
  alt="Grade"> <img
  src="https://img.shields.io/badge/Status-Completed-brightgreen.svg"
  alt="Status"> </p>

# Libft

[![build](https://github.com/vinicius507/libft/actions/workflows/build.yml/badge.svg)](https://github.com/vinicius507/libft/actions/workflows/build.yml)
[![norminette](https://github.com/vinicius507/libft/actions/workflows/norminette.yml/badge.svg)](https://github.com/vinicius507/libft/actions/workflows/norminette.yml)

**My very first library in C, made for 42 School.**

This repository contains a collection of functions that replicate some of the
standard C library functions as well as introduce additional utility functions.
The library is primarily intended for use within the 42 School curriculum.

## Introduction

The **Libft** library provides a range of functions to perform
various operations on strings, files, and linked lists. It serves as a
foundational toolset for C programming, aiding in tasks such as memory
manipulation, string processing, and data structure management. Some functions
are optimized for performance, while others provide essential utilities.

## Usage

> [!WARNING]
>
> During the 42 curriculum you are required to develop and use your **Libft**
> library.

### From Source

Requirements:

- Clang 12
- GNU Make

Steps:

1. Clone this repository to your local machine.
2. Navigate to the repository's root directory.
3. Run `make -C ./libft` to compile the library.

A compiled library named `libft.a` will be generated. You can link this library
with your C programs to access the provided functions.

### Using Nix

This repository contains a Nix Flake that provides a Nix package for Libft:

You can build the library using `nix build`:

```sh
nix build github:vinicius507/libft#libft
```

Or add it to a `nix develop` shell:

```nix
{
  inputs = {
    nixpkgs.url = "nixpkgs";
    libft = {
      url = "github:vinicius507/libft";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
  outputs = {
    self,
    nixpkgs,
    libft,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      overlays = [
        # Adds the libft library and header file to the shell LIBRARY_PATH and C_INCLUDE_PATH
        libft.overlays.libft
        # Overrides the stdenv from mkShell to use clang 12
        libft.overlays.devshell
        self.overlays.ft_malcolm
      ];
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        bear
        clang-tools_12
        gnumake
        norminette
        valgrind
        pkgs.libft
      ];
    };
  };
}
```

## Related Projects

1. [Get Next Line](https://github.com/vinicius507/get_next_line).
2. [42 Printf](https://github.com/vinicius507/ft_printf).
