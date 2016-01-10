# IDE

Szoftverfejlesztés során rengeteget segít, ha az egyes eszközöket (verziókezelő, fordító, debugger stb.) együtt tudjuk kezelni. Az integrált fejlesztőkörnyezetek (IDE, _integrated development environment_), egységes felület nyújtanak ezek kezeléséhez. Gyakori, hogy ezek az alkalmazások valójában parancssoros alkalmazásokat hívnak (`make`, `java`, ...) és azok kimenetét jelenítik meg.

Népszerű fejlesztőkörnyezetek:

* [Code::Blocks](http://www.codeblocks.org/)
* [Eclipse](http://www.eclipse.org/ide/)
* [IntelliJ IDEA](IntelliJ IDEA)
* [NetBeans](https://netbeans.org/)
* [Visual Studio](https://www.visualstudio.com/)
* [Xcode](https://developer.apple.com/xcode/)

## Eclipse

Most az [Eclipse C/C++](https://www.eclipse.org/cdt/) fejlesztőkörnyezetet használjuk. A C/C++ nyelvek továbbra is a legnépszerűbb ([TIOBE Index](http://www.tiobe.com/index.php/content/paperinfo/tpci/index.html)) és a leggyorsabbak ([The Computer Language Benchmark Game](http://benchmarksgame.alioth.debian.org/)) között vannak.

### Szerkesztő

A kód szerkesztésében az egyik legfontosabb komponens a szövegszerkesztő, ami kódkiemeléssel (*syntax highlight*) segíti a fejlesztő munkáját.

### Debugger

`gdb` (GNU Debugger)
