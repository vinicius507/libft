{
  inputs.nixpkgs.url = "nixpkgs";

  outputs = {
    self,
    nixpkgs,
  }: let
    allSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];

    forEachSystem = f:
      nixpkgs.lib.genAttrs allSystems (system:
        f {
          pkgs = import nixpkgs {
            inherit system;
            overlays = builtins.attrValues self.overlays;
          };
        });
  in {
    checks = forEachSystem ({pkgs}: {
      norminette-check = pkgs.stdenvNoCC.mkDerivation {
        name = "norminette-check";
        src = ./libft;
        dontBuild = true;
        doCheck = true;
        checkPhase = with pkgs; ''
          ${norminette}/bin/norminette $src
        '';
        installPhase = "touch $out"; # Derivation must build an output.
      };
    });
    packages = forEachSystem ({pkgs}: {
      default = pkgs.libft;
      libft = import ./nix/pkgs/libft.nix {
        inherit (pkgs) lib;
        inherit (pkgs.llvmPackages_12) stdenv;
      };
    });
    overlays = {
      default = self.overlays.libft;
      devshell = final: prev: {
        mkShell = prev.mkShell.override {
          inherit (final.llvmPackages_12) stdenv;
        };
      };
      libft = final: _: {
        libft = self.packages.${final.system}.libft;
      };
    };
    devShells = forEachSystem ({pkgs}: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          norminette
          valgrind
        ];
      };
    });
  };
}
