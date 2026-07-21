{
  description = "D-SH Dashboard System - Build Package and Development Shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        buildInputs = with pkgs; [
          cmake
          ninja
          pkg-config
          gnumake
          gcc
          gtest
          ftxui
        ];
      };
      shellHook = ''
        echo "D-SH Dashboard Development Environment Loaded!"
        echo "C++ Compiler: $(g++ --version | head -n 1)"
        echo "CMake version: $(cmake --version | head -n 1)"
      '';

      packages.${system}.default = pkgs.stdenv.mkDerivation {
        name = "dsh-dashboard";
        src = ./.;

        nativeBuildInputs = with pkgs; [
          cmake
          ninja
          pkg-config
        ];

        buildInputs = with pkgs; [
          ftxui
        ];

        buildPhase = ''
          cmake -B build -G Ninja -DCMAKE_INSTALL_PREFIX=$out
          cmake --build build
        '';

        installPhase = ''
          cmake --install build
        '';
      };
    };
}
