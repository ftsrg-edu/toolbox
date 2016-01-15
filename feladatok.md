# Feladatok

1. Fordítsuk le a 2048 játék C nyelvű klónját: [2048.c](https://github.com/mevdschee/2048.c)

1. Fordítsuk le a [GNU Chess](http://www.gnu.org/software/chess/) és az [XBoard](http://www.gnu.org/software/xboard/) alkalmazásokat.


1. (*haladó*) Készítsünk Bash nyelven [Quine alkalmazást](https://en.wikipedia.org/wiki/Quine_%28computing%29). A Quine egy olyan program, ami nem olvas semmilyen bemenetet (beleértve a saját forrásfájlját) és kiírja a saját forráskódját.

    [quine.sh](https://gist.github.com/scvalex/5360004)


# Megoldások

1. A README fájl alapján értelemszerűen végrehajtható.

1. Az XBoardhoz elég sok mindent fel kell tenni. Trükk: az Ubuntu Launchpad oldalán meg tudjuk nézni, hogy milyen függőségei vannak a buildnek: a <https://launchpad.net/ubuntu/+source/xboard/4.8.0-2> oldalon a `xboard_4.8.0-2.dsc` fájlban a `Build-Depends` részt kell nézni.

  Az XBoard induláskor a `fairymax` backendet keresi, ezt cseréljük le az **Engine** menüben a **Load New 1st Engine** opcióval.
