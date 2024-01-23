{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = with pkgs; [
    boost
    gbenchmark
    cmake
  ];
}