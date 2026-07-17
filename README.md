# D-SH (DASH)
> Please let me know if you find any issues inside this project (code, README, etc)

> The first (test) version was made without an internet connection so yeah...

A TUI dashboard that will be able to display system info, network info, current time and more. 

## Current version
> This segment will not always be updated on the dev branch

The current version only shows the current time (live updating).

## Usage and Installation
There are 3 main ways to use the D-SH dashboard.

### Build and use locally
First you need to build the project using cmake. I recommend adding a build folder before building. Then you can immediatly use the project inside the build folder.
```bash
mkdir build
cd build
cmake ..
make
./d-sh
```

### Install using CMake
You can also install the dashboard on your pc by using CMake. I also recommend using a build folder for this one.
```bash
mkdir build
cd build
cmake ..
make install
```
And then you can use d-sh everywhere.

### Install using NixOS
You can also install the dashboard on your NixOS system inside your system flake.
```nix /etc/nixos/flake.nix
{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    d-sh = {
      url = "github:NilsPils06/D-SH";
    };
  };

  outputs = { self, nixpkgs, d-sh, ... }: {
    nixosConfigurations.your_pc = nixpkgs.lib.nixosSystem {
      system = "x86_64-linux";
      modules = [
        ./configuration.nix
        {
          environmentModules.systemPackages = [
            d-sh.packages.${pkgs.system}.default
          ];
        }
      ];
    };
  };
}
```
