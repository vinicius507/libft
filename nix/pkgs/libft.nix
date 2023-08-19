{
  lib,
  stdenv,
}:
stdenv.mkDerivation {
  pname = "libft";
  version = "1.0.0";
  src = ../../libft;
  installPhase = ''
    mkdir -p $out/lib
    cp libft.a $out/lib
    cp -r include $out/include
  '';
  meta = with lib; {
    license = licenses.agpl3Only;
  };
}
