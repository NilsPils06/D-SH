# D-SH (pronounced DASH)
> Please report any issues you find inside this project (code, README, etc)

A TUI dashboard (using FTXUI) that displays some system info, current time and will display more in the future.
*Built to be minimalistic, efficient and fast.*

## Current version (0.1)
> This segment will not always be updated on the dev branch

The current version shows the following:
- Current time (live updating)
- Host info (contains System name and Kernel Release)
- Uptime (live updating)
- Battery info. 
- CPU temperature
It also makes use of a config file for customization.

The next version will feature RAM usage, Load average and AMD GPU stats.

## Usage and Installation
There are 3 main ways to use the D-SH dashboard.

### Build and use locally
First you need to build the project using CMake. I recommend creating a build folder before building. Then you can immediately use the project inside the build folder.
```bash
mkdir build
cd build
cmake ..
make
./d-sh
```

### Install using CMake
You can also install D-SH on your pc by using CMake. A build folder is recommend.
```bash
mkdir build
cd build
cmake ..
sudo make install
```
And then you can use D-SH everywhere.

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
          environment.systemPackages = [
            d-sh.packages."x86_64-linux".default
          ];
        }
      ];
    };
  };
}
```

### Config
D-SH makes use of a config.ini file created at ~/.config/d-sh/. The current version of the config parsing makes use of a simple true/false value for every module.
```ini
[modules]
clock=true
battery=true
uptime=false
host=false
temp=true
```
