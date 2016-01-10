# Szakkör bevezető

## Motiváció

A mérnök informatikusként végzettek egyik fontos képessége, hogy jó szoftverfejlesztők legyenek. A szoftverfejlesztés nem olyan kiforrott terület, mint más mérnöki diszciplínák -- pl. az építészet és a gépészet --, ezért a módszertana is alapvetően különbözik azoktól. A legtöbb szoftverfejlesztési feladat során ritkán van szükség bonyolult képletekre és mély elméleti ismeretekre. Egy projekt sikere mérnöki szempontból leginkább azon múlik, hogy a fejlesztők képesek-e az üzleti igényeknek megfelelően  megtervezni a rendszert és azt hatékonyan elkészíteni. Fontos, hogy a szoftver ne "egyszer lefusson", hanem megfelelően karbantartható és tesztelhető kódból álljon, azt szükség esetén más megérteni és módosítani tudja.

Egy szoftver elkészítéséhez általában sok különböző eszköz használata szükséges. Ezekbe beletartozik az operációs rendszer, a verziókezelő, a szövegszerkesztő, az integrált fejlesztőkörnyezet (IDE), a build eszköz, a parancssoros értelmező, a webböngésző és így tovább. Minden fejlesztőnél egyedi, hogy milyen eszközökből áll a "szerszámosládája".

A szakkör célja, hogy bemutassa azokat az eszközöket, amelyeket mi is használunk a szoftverfejlesztéshez. Többnyire olyan eszközökről lesz szó, amelyek évek-évtizedek óta léteznek és mára széleskörűen elterjedtek, ennek megfelelően a legtöbb tapasztalt szoftverfejlesztő ismeri, sőt aktívan használja őket.

## Nyílt forráskódú szoftverek

A szoftverfejlesztők szerszámosládásjában szereplő szoftverek többsége nyílt forráskódú, azaz a szoftver kódja szabadon elérhető az interneten. A nyílt forráskódú szoftverek számos előnnyel rendelkeznek: a bennük található hibák könnyebben jelenthetők és javíthatók, könnyű csatlakozni a szoftver fejlesztéséhez, a szoftver az eltérő felhasználói igényeknek kielégítéséhez többféle különböző irányba is fejlődhet.

**Olvasnivaló:** Eric S. Raymond, [The Cathedral and the Bazaar](http://www.catb.org/esr/writings/cathedral-bazaar/cathedral-bazaar/index.html).

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
