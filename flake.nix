{
  inputs = {
    nixpkgs.url = "nixpkgs";
    ft-nix = {
      url = "github:vinicius507/42-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
  outputs = {
    self,
    nixpkgs,
    ft-nix,
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
            overlays = [ft-nix.overlays.norminette];
          };
        });
  in {
    packages = forEachSystem ({pkgs}: {
      default = self.packages.${pkgs.system}.libft;
      libft = pkgs.stdenv.mkDerivation {
        pname = "libft";
        version = "1.0.0";
        src = ./.;
        nativeBuildInputs = with pkgs; [
          llvmPackages_12.libcxxClang
        ];
        installPhase = ''
          mkdir -p $out/lib
          mkdir -p $out/include

          cp libft.a $out/lib
          cp include/libft.h $out/include
        '';
        meta = with pkgs.lib; {
          license = licenses.agpl3Only;
        };
      };
    });
    devShells = forEachSystem ({pkgs}: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          llvmPackages_12.libcxxClang
          norminette
          valgrind
        ];
      };
    });
  };
}
