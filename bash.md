# Linux

## Fájlrendszer

### Fontos könyvtárak

A Linux fájlrendszer egy közös gyökérkönyvtárral rendelkezik, ez a `/`, ezt gyakran _root könvyvtárnak_ is nevezik.

A legfontosabb könyvtárak:

* `/bin`: _binaries_, felhasználói parancsokhoz tartozó binárisok, pl. `bash`, `ls`, `tar`.
* `/dev`: _devices_, eszközök, pl. a `/dev/null`.
* `/etc`:  _et cetera_, rendszerszintű konfigurációs állányok, pl. az `/etc/hosts` és az `/etc/hostname`.
* `/home`: a felhasználók saját _home könyvtárai_ itt találhatók.
* `/lib`: _libraries_, függvénykönytárak.
* `/proc`: _processes_, virtuális fájlrendszer a folyamatok és más kernelszintű adatok lekérésére.
* `/root`: a `root` felhasználó konfigurációs állományait tartalmazza. Nem összetévesztendő a `/` root könyvtárral.
* `/sbin`: _system binaries_, rendszerszintű bináris állományok.
* `/tmp`: _temporary_, vagyis átmeneti fájlok. Újraindításkor törlődik a tartalma.
* `/usr`: _user_, csak olvasható felhasználói adatok. Másodlagos hierarchia, azaz szintén tartalmaz `bin`, `lib` és `sbin` könyvtárakat. A `/usr/bin` könyvtárban található sok fontos parancs binárisa.

A `/dev/null` könyvtárba irányított adatfolyammal semmi sem történik -- nem íródik ki se a szabványos kimenetre, se fájlba, se más eszközbe.

**Érdekesség:** az informatikai szleng része a _"ment a devnullba"_ kifejezés.

### Jogosultságok

A Linux fájlrendszerében kezdetektől fogva kiemelt szerepet kapott az, hogy az egyes állományok hozzáférését precízen szabályozni tudjuk \(access control\). Minden fájlhoz tartozik egy _tulajdonos felhasználó_ \(owner\) és _tulajdonos csoport_ \(group\). Beállítható, hogy az owner, a group és a többi felhasználó milyen jogosultságokkal rendelkezzenek: tudják-e azt _olvasni_ \(read\), _írni_ \(write\) és azt _futtatni_ \(execute\). Az `ls -l` parancsnál ezeket a jogosultságokat `rwxrwxrwx` formátumban láthatjuk.

Egy fájl futtathatóvá tételéhez használjuk az alábbi parancsot:

```bash
chmod +x fájlnév
```

### Rendszergazdai jogosultságok

A `sudo` \(_superuser do_\) paranccsal ...

**Mikor van a leggyakrabban szükség rendszergazdai jogosultságokra?** A legtöbb fejlesztési feladat elvégezhető rendszergazdai jogosultságok nélkül. Általában a következő feladatoknál van szükségünk rendszergazdai jogosultságokra:

* Csomagok telepítése és frissítése: `apt-get install`, `apt-get update`, `apt-get upgrade`.
* Program vagy függvénykönyvtár telepítése forráskódból: `make install`.
* Rendszerkonfigurációs állományok módosítása, pl. `nano /etc/hosts`.
* Jogosultságok beállítása, pl. `sudo chmod 644 *.html`.
* Tulajdonos beállítása, pl. `sudo chown -R myuser:myuser /var/lib/myapp/`.

Az `su` \(_switch user_\) paranccsal felhasználót válthatunk. Az `su -` parancs alapértelmezés szerint a `root` felhasználóra vált. Ha ismerjük a jelszavát, akkor rendszergazdai jogosultságokhoz juthatunk. Általában nincs szükség az `su` használatára. Ubuntu rendszeren alapértelmezés szerint a `root` jelszava nincs beállítva, így nem is tudunk belépni vele.

A `sudo` hasonló a Windows rendszerekben használt UAC \(User Account Control\) megoldáshoz.

**Fontos.** Bár a nevük hasonló és bizonyos problémákat mindkettővel meg lehet oldani, a `su` és a `sudo` parancsok teljesen különbözőek.

## Bash

A Bash nem csak futtatókörnyezetet, hanem egy _szkriptnyelvet_ \(script language\) is definiál. Az általános célú programozási nyelvekkel \(pl. C, C++\) szemben a szkriptnyelvek általában a következő jellegzetességekkel rendelkeznek:

* Dinamikus tipizálás: a változók típusát nem definiáljuk előre.
* Fordító helyett futás közben _értelmező_ \(interpreter\) futtatja.
* Akár soronként is értelmezhető.
* Minden futási időben értékelődik ki.

### Alapvető fájlkezelő parancsok

| parancs | jelentés |
| --- | --- |
| `pwd` | _print working directory_: kiírja az aktuális könyvtárat |
| `mkdir test` | _make directory_: `test` könyvtár létrehozása |
| `cd test` | _change directory_: könyvtár váltása |
| `touch 01.txt` | fájl hozzáférési idő módosítása vagy fájl létrehozása |
| `echo 02` | kiírás |
| `ls` | könyvtár tartalmának listázása |
| `ls -la` | részletes lista |
| `cp 02.txt 03.txt` | _copy_: másolás |
| `mv 02.txt 03.txt` | _move_: mozgatás vagy átnevezés |
| `cat 02.txt` | _concatenate_: fájlok tartalmának összefűzése és kiírása |
| `clear` | képernyő törlése |
| `chmod +x my.sh` | _change mode_: jogosultságok beállítása |

A Windows-zal ellentétben Bash alatt a keresett elérési útvonalban _nem szerepel az aktuális könyvtár_, csak a `PATH` környezeti változó.

**Megjegyzés.** Törekedjünk arra, hogy használjuk a `TAB` billentyűvel az automatikus parancs- és fájlnév kiegészítést. Amennyiben több lehetőség adódik a kiegészítésre, akkor a `TAB` kétszeri lenyomása után ezekről listát kapunk. A paramétereknél is érdemes a `TAB` billentyűt használni, mert különböző típusú elemek kiegészítését is tudja a Bash shell.

### Alapvető parancsok

Ezek a fájlok a `/bin`, `/sbin` és `/usr/bin` könyvtárakban található.

`echo` `chmod` `chown` `cat` `cut`

CSV fájlok. Egyszerűségük ellenére a CSV állományokat elterjedten alkalmazzák a rendszerüzemeltetéstől kezdve különböző -- több gigabájtos -- nagy adathalmazok elemzéséig.

### Csővezetékek és szűrők

A Bash támogatja a _csővezetékek és szűrők_ \(pipes and filters\) architekturális modell alkalmazását. Az egyes alkalmazásokat különböző szűréseket és transzformációkat végeznek, az alkalmazásokat pedig csővezetékek kötik össze. A vezetékeket a `|` \(pipe\) karakterrel jelöljük. Például a számjegyet tartalmazó fájlneveket az alábbi paranccsal írathatjuk ki:

```bash
$ ls | grep "[0-9]"
```

A `/proc/cpuinfo` fájlban található sorok számát az alábbi paranccsal kaphatjuk meg:

```bash
$ cat /proc/cpuinfo | wc -l
```

**Tipp:** ha csak egy fájlon végzünk műveletet, akkor általában nincs szükség a `cat` parancsra. A parancs felesleges használatának külön neve is van: _"useless use of _`cat`_"_. A kapcsolódó hívják. _“The purpose of cat is to concatenate \(or ‘catenate’\) files. If it's only one file, concatenating it with nothing at all is a waste of time, and costs you a process.”_

Összetettebb programok elkészítésére nem javasolt a Bash használata. Ökölszabályként az 1000 sornál hosszabb Shell szkriptek kódok karbantartása már közel lehetetlen. Alternatívaként javasolt valamilyen fejlettebb szkriptnyelv, pl. a [Python](https://www.python.org/) vagy a [Perl](https://www.perl.org/) használata.

### Gyorsbillentyűk

A `↑` és `↓` billentyűk segítségével lépkedjünk a korábbi parancsok között. A konzolkimenetben való navigációra a `Shift`+`Page Up` és `Shift`+`Page Down` billentyűkombinációk használhatók. A korábbi parancsok között a `Ctrl`+`R` megnyomása után lehet keresni \(reverse incremental history search mode\). Ilyenkor a `Ctrl`+`R` többszöri megnyomásával lehet visszafelé lépkedni a korábbi parancsok között. Ha megtaláltuk, amit keresünk, akkor az `Enter` segítségével végrehajthatjuk, vagy az `Escape` segítségével szerkeszthetjük is. A `Ctrl`+`U` segítésével lehet a parancs kurzor előtti részét kitörölni.

## Szkriptelés más platformokon

### Windows szkriptek

Microsoft Windows alatt hagyományosan a batch fájlokat \(`.bat`, ritkábban `.cmd`\) használták szkriptelésre.

Egy példa batch fájl:

```batch
@echo off

rem Recursively print all files in directory
for /r %%i in dir do (
    echo %%i
)
```

A batch futtatókörnyezet kevesebb funkcióval rendelkezik, mint a Bash, így általában még nehezebb áttekinthetőbb alkalmazásokat készíteni. Ennek a megoldására készítették a [PowerShell](https://en.wikipedia.org/wiki/Windows_PowerShell) nyelvet. A PowerShell több mint 15 évvel a Bash után született, így jóval modernebb szemléletű: szövegfolyamok mellett objektumok kezelésére is képes, valamint képes a Microsoft [.NET keretrendszerére](http://www.microsoft.com/net) keretrendszerével szorosan együttműködni.

A PowerShell programozás hangsúlyosan szerepel az Informatikai technológiák szakirány [Intelligens rendszerfelügyelet](https://inf.mit.bme.hu/edu/courses/irf/materials) tárgyán.

## Platformfüggetlen szkriptek

Platformfüggetlen szkriptek készítésére -- néhány alapelv betartásával -- kiválóan használhatók a korábban már említett Python és Perl nyelvek. Valamivel kevésbé elterjedtek erre a célra, de szintén jól alkalmazhatók a Lua és a Ruby nyelvek. Egy Java-alapú szkriptnyelv a Groovy, amit a Gradle build keretrendszer is használ.

**Érdekesség:** a [Batsh](https://github.com/BYVoid/Batsh) projekt egy olyan programozási nyelvet definiál, ami a batch és a Bash szkriptek funkcióinak metszetét valósítja meg, így a Batsh nyelven készült kódból batch és Bash szkript is generálható.

