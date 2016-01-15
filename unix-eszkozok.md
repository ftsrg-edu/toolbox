## Unix-alapú rendszerek

Sok eszköz története a Unix-alapú rendszerekig nyúlik vissza. Ezeket eredetileg nagy mainframe számítógépekre írták.

### Történet

A lyukkártyás számítógépek korában újdonságnak számított, hogy ezek a rendszerek olyan _rendszerhéjjal_ (shell) rendelkeztek, amely parancssoros kezelőfelületet biztosított. Ezeket _elektromos írógépekkel_ (TeleTYpewriter, TTY) vezérelték. Több, manapság is használt kifejezésnek az eredete itt keresendő: ezért pl. az új sor beszúrásához használt karakterek neve a _kocsi vissza_ (carriage return, `\r`) és a _soremelés_ (line feed, `\n`).

**Fontos.** A napjainkban elterjedt operációs rendszerek különböző módon reprezentálják a sortörést: Linuxon `\n`, Mac OS-en `\r`, míg Windowson `\r\n`.

A Unix-alapú operációs rendszerek közé tartozik több szerver operációs rendszer (pl. a HP Unix és a hszk ural2-n futó Solaris), a Mac OS, az iOS és a Linux kernelre építő rendszerek.

### Unix filozófia

A [Unix filozófia](http://en.wikipedia.org/wiki/Unix_philosophy) olyan fejlesztési alapelv, amely azt célozza meg, hogy kis méretű, jól használható szoftverek készüljenek, amelyek egy jól körülhatárolt célfeladat megvalósítására alkalmasak. Ezek a programok legtöbbször szöveges bemenetet olvasnak és szöveges kimenetet állítanak elő. Az egyes programok csővezetékeken (_pipes_) keresztül kommunikálnak.

A csővezetékek kitalálója így foglalta össze a Unix filozófiát: _"This is the Unix philosophy: Write programs that do one thing and do it well. Write programs to work together. Write programs to handle text streams, because that is a universal interface."_

A Unix filozófia gyakran visszatérő tervezési alapelve a szerszámosládánkban található szoftvereknek.

### Linux kernel

Napjainkban sok operációs rendszer épít a Linux rendszermagra, azaz a Linux kernelre. A Linux-kernel sokoldalúságát bizonyítja, hogy különböző verziói megtalálhatók a szuperszámítógépektől kezdve a laptopokon keresztül a hordozható okoseszközökben és különböző szenzorokban.

A szoftverfejlesztés során a Linux leggyakrabban mint szerver operációs rendszer kerül elő. A különböző Linux operációs rendszereket _disztribúciónak_ (distribution) nevezik, ezek száma mostanra több százra tehető. A disztribúciók között felhasználói szempontból a legfontosabb különbség a használt csomagkezelő rendszer és a grafikus felhasználói felület típusa (vagy a grafikus felület hiánya). Szerencsére néhány disztribúció ismeretében a legtöbben könnyen elboldogulhatunk. A legfontosabbak:

* Debian (Ubuntu, Mint)
* Red Hat (CentOS)
* Slackware (Fedora)
* Arch
* Gentoo

Egyszerű használhatóságának és jó támogatottságának köszönhetően az Ubuntu mára széleskörűen elterjedt, nagyon sok felhőalapú szolgáltatás alapértelmezettként ilyen operációs rendszert telepít a virtuális gépekre.

Az Ubuntu asztali számítógépekre is telepíthető, különböző ablakozó felületekkel. Az "alap" Ubuntu a Unity, az Ubuntu GNOME a GNOME, a Mint a Cinnamon, a Kubuntu a KDE, a Xubuntu az XFCE felületet tartalmazza. Az Ubuntu természetesen telepíthető virtuális gépként is -- ekkor érdemes valamelyik kevésbé erőforrásigényes ablakozó felületet (pl. XFCE) használni.

### Bash

A Linux rendszereken a leggyakoribb a Bash (Bourne Again Shell) rendszerhéj. A Bash egy magasszintű programozási nyelvet nyújt, amellyel kifejezetten összetett (bár gyakran nehezen olvasható és karbantartható) szkriptek készíthetők. A bemutatott példákat mind Bash shellen futtattuk, de a legtöbb módosítás nélkül működne más shellen is (ksh, zsh stb.).

### Unix eszközök


Az egyik legfontosabb parancs a `man`, amellyel az egyes szoftverek felhasználói _útmutatóját_ (manual) nézhetjük meg. Keresni a `/` gomb lenyomása után tudunk, a találatok között az `n` billentyűvel lehet léptetni. Kilépni a `q` billentyűvel tudunk.
Míg régen gyakran a "man page" alapján kellett egy szoftver működését megismerni, manapság általában könnyebb rákeresni az interneten a megoldandó problémára vagy hibaüzenetre.

Az egyes parancsoknak saját súgójuk is van, ami leggyakrabban a `--help` kapcsolóval érhető el. Ez gyakran tömörebb és érthetőbb a man paranccsal kapott oldalnál.

# Unix eszközök

Nézzünk meg néhány tipikus Unix eszközt egy példán keresztül.

## Prímszámlálás

C nyelven készítettünk egy programot (`primes.c`) az 1 és 100 000 közötti prímszámok számának meghatározására.

### GCC

Fordítsuk le a programot. C/C++ nyelvű szoftverek fordításához a legtöbbször a GCC (GNU Compiler Collection) eszközt használjuk. Ennek két legfontosabb parancsa a `gcc` és a `g++`. A kettő között apró különbségek vannak, amelyekből a legfontosabb, hogy alapértelmezés szerint különböző függvénykönyvtárakat támogatnak. Használjuk most a `g++` eszközt!

```bash
$ g++ primes.c -o primes
```

(`gcc` esetén például a `math.h` használatához a `-lm` paraméterrel kell kiegészítenünk a hívást.)

A programot a `./primes` paranccsal futtathatjuk.

### Makefile

Szeretnénk, hogy a fordítás egyszerűen elindítható legyen és ne kelljen mindig egy hosszú parancsot beírni. Erre a célra a `make` eszközt érdemes használni, amelyben megadhatunk különböző célokat (_goal_). Indítsünk egy szövegszerkesztőt:

```bash
$ nano Makefile
```

Definiáljuk az `all` célt:

```Makefile
all:
  g++ primes.c -o primes
```

Adjunk hozzá egy külön célt a teszteléshez:

```Makefile
all: build

build:
	g++ primes.c -o primes
test:
	./primes
```

### Teljesítménymérés

Vizsgáljuk meg, hogy mennyi idő alatt fut le a program. Ehhez elég, ha a `time` parancsot a program hívása elé tesszük:

```bash
$ time ./primes
```

Látható, hogy a programnak néhány másodpercre szüksége van a számításhoz, azaz a program meglehetősen lassú.

### Különböző verziók kezelése

A programot elküldtük egy kollégánkban [emailben](http://theoatmeal.com/comics/email), hogy próbálja meg gyorsítani. Közben mi is fejlesztettük a programot és paraméterezhetővé tettük (`primes-a.c`), majd megkaptuk az optimalizált változatot (`primes-b.c`).

Vizsgáljuk meg, hogy hogyan módosította a kollégánk a programot!

```bash
$ diff -u primes.c primes-b.c
```

Az optimalizáláshoz az [Eratoszthenész szitája](http://hu.wikipedia.org/wiki/Eratoszthenész_szitája) nevű algoritmust használta.

Vizsgáljuk meg, hogy a két új implementáció miben különbözik:

```bash
$ diff -u primes-a.c primes-b.c
```

#### Three-way merge

A három fájlt egyesíthetjük egy az ún. [_three-way merge_](http://en.wikipedia.org/wiki/Merge_%28revision_control%29#Three-way_merge) művelettel. Parancssorban erre a `diff3` eszközt használjuk.

```bash
$ diff3 --merge primes-a.c primes.c primes-b.c
```

Külön fájlba íráshoz irányítsuk át a kimenetet az alábbi módon:

```bash
$ diff3 --merge primes-a.c primes.c primes-b.c > primes-merged.c
```

#### Meld

A three-way merge-höz grafikus felületet biztosít a [Meld](http://meldmerge.org/) eszköz. Ez alapértelmezés szerint nem része a legtöbb disztribúciónak, de Ubuntu alatt egyszerűen telepíthető az alábbi paranccsal:

```bash
$ sudo apt-get install meld
```

A Meld képes grafikusan is megjeleníteni az összefésülendő fájlokat, ami nagyban segít bonyolultabb műveletek esetén.

### Kódsorok megszámolása

Egy szoftver forráskódját gyakran jellemezzük azzal, hogy hány sorból áll. Ebben segítséget nyújt a `wc` (_word count_) eszköz.

```bash
$ wc primes-merged.c
```

Esetünkben a `-l` kapcsolót érdemes használni, így csak a sorok számát fogja kiírni.

#### Kommentek

Szintén gyakori jellemző a kommentet tartalmazó sorok száma. Az egyszerűség kedvéért most csak az egysoros kommentekkel foglalkozunk.

A kommentezett sorok megtalálásához a `grep` (_**g**lobally search a **r**egular **e**xpression and **p**rint_) eszközt használjuk, amely képes arra, hogy csak az adott reguláris kifejezésre (*regular expression*) illeszkedő sztringet tartalmazó sorokat adja vissza.  A reguláris kifejezésekhezhez leírás a <http://www.regular-expressions.info/>, interaktív gyakorlóprogram a <http://regexone.com/> weboldalon található.

**Megjegyzés.** A reguláris kifejezésekre több [különböző szabvány](https://en.wikipedia.org/wiki/Regular_expression#Standards) is létezik. Változó, hogy az egyes implementációk melyik szabványt és milyen mértékben valósítják meg, ahogy az alábbi idézet is bizonyítja: _I define UNIX as "30 definitions of regular expressions living under one roof"._ ([Donald Knuth](https://en.wikiquote.org/wiki/Donald_Knuth))

```bash
$ grep "//" primes-merged.c
```

Látható, hogy ez még nem tökéletes, javítsuk:

```bash
$ grep "^\s*//" primes-merged.c
```

A sorok megszámolásához használjuk a `wc` parancsot:

```bash
$ grep "^\s*//" primes-merged.c | wc -l
```

#### Üres sorok elhagyása

A `grep` képes arra is, hogy az adott reguláris kifejezésre **nem illeszkedő** sorokat elhagyja.

```bash
$ grep -v "^\s*$" primes-merged.c
```

Egyesítve:

```bash
$ grep -v "^\s*$" primes-merged.c | grep -v "^\s*//" | wc -l
```

Készítsünk a két reguláris kifejezésből egyet az `(a|b)` ("a" vagy "b") konstruktcióval. Ehhez néhány karakter (a zárójelek és a pipe) escape-elésére lesz szükség:

```bash
$ grep -v "^\s*\($\|//\)" is_prime_2.c | wc -l
```

#### Unix vezérlőkarakterek

Mi történik, ha a `wc` parancsot paraméterek nélkül hívjuk?

A Unix operációs rendszerek alatt lehetőségünk van ún. [vezérlőkarakterek](https://en.wikipedia.org/wiki/Control_character) (*control characters*) használhatára. A karakterek a `Ctrl` billentyűvel érhetők el, pl. a `^D` a `Ctrl`+`D` billentyűkombináció lenyomását jelenti.

karakter             | billentyű
-------------------- | -------------
horizontal tab       | `^I`
line feed            | `^J`
carriage return      | `^M`
end of transmission  | `^D`

Szintén a `Ctrl` billentyűvel érhetők el olyan [jelzések](https://en.wikipedia.org/wiki/Unix_signal) (*signals*), amelyekhez nem tartozik karakterkód. Pl. a `Ctrl` + `C` a `SIGINT` jelzést, azaz az `INT` jelzést küldi a folyamatnak.

jelzés               | billentyű
-------------------- | -------------
`SIGINT`             | `^C`
`SIGTSTP`            | `^Z`
`SIGQUIT`            | `^\`

Nézzünk egy példát a `wc` paranccsal.

```bash
$ wc -l
hello
world
^D
```

Az eredmény:

```
2
```

Próbáljuk ki az `INT` jelzést. Ezzel leállítjuk az éppen futó alkalmazást.

## Csomagkezelő

A Linux-alapú rendszerek egyik központi komponense a csomagkezelő (*package manager*). Ahelyett, hogy minden alkalmazás saját telepítővel rendelkezne, a telepítés a csomagkezelő végzi. A csomagkezelő feladatai közé tartozik a szükséges függőségek feloldása és a telepített csomagok frissítése is.

Ubuntu Linux alatt az `apt-get install` paranccsal telepíthetünk csomagokat. A telepítéshez rendszergazdai jogosultságok szükségesek, ezért a parancsot az alábbi formában használjuk:

```bash
$ sudo apt-get install csomagnév
```

A csomagkezelővel telepíthetünk függvénykönyvtárakat (_library_) is. A függvénykönyvtárak neve `lib`-bel kezdődik, a forráskódot a `-dev` végű csomag tartalmazza. Például a [Boost C++ Libraries](http://www.boost.org/) reguláris kifejezéseket támogató modulja a a `libboost-regex-dev` csomagban található.

## Érdekességek

**Kapcsolódó olvasmány:** a prímszámok és matematika története iránt érdeklődőknek érdekes olvasmány Marcus du Sautoy [A prímszámok zenéje](http://moly.hu/konyvek/marcus-du-sautoy-a-primszamok-zeneje) c. ismeretterjesztő könyve.

**Project Euler:** érdekes algoritmuselméleti problémákat sorol fel a [Project Euler](https://projecteuler.net/) oldala. Természetesen nem kell -- rövid idő alatt nem is lehet -- minden feladatot megoldani. Ehelyett lehet vele gyakorolni az algoritmizálást, állásinterjúra készülni vagy problémákat keresni egy új programnyelv alapjainak megtanulásához.

**Magyar Linux:** mi történne, ha a Linuxban szereplő angol kifejezéseket tükörfordítással nagyarra fordítanánk? Bemutatja ez az 1999-es [Impulzus cikk](http://w3.impulzus.com/archivum/cikk/46/).
