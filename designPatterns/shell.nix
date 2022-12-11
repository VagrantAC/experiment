{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  nativeBuildInputs = [
    pkgs.gradle_6
    pkgs.jdk11
  ];
}
