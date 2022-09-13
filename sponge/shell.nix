{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  nativeBuildInputs = [ 
    pkgs.gcc8
    pkgs.cmake
    pkgs.neovim
  ];
}
