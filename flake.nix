{
  description = "C++ Dashboard TUI Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        buildInputs = with pkgs; [
          cmake
          ninja
          gnumake
          gcc
          pkg-config

          ftxui
          ncurses

          gdb
        ];

        shellHook = ''
          echo "🚀 Dashboard TUI Development Environment Loaded!"
          echo "C++ Compiler: $(g++ --version | head -n 1)"
          echo "CMake version: $(cmake --version | head -n 1)"
        '';
      };
    };
}
