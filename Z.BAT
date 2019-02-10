del ..\akill.zip
del *.~??
pkzip -Sn0n0  -ex ..\akill *.*
pkzip -d ..\akill  *.exe *.obj *.tds *.ils
pkzip ..\akillexe  *.exe