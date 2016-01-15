# SSH

## SSH kliensek

### Linux/Mac OS

Terminálból az `ssh` eszköz használata javasolt, amivel az alábbi módon csatlakozhatunk távoli számítógépekhez:

```bash
ssh felhasználónév@hosztnév
```

### Windows

A legelterjedtebb eszköz a [PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/). (Bár a rövidítésben szerepel a TTY, a PuTTY rövidítésnek nincs külön jelentése. A *putty* egyébként angolul gittet jelent.)

Szintén jól használható a [Cygwin](https://www.cygwin.com/) az `openssh` csomag telepítésével. **Figyelem:** a Cygwin alapból nem telepíti ezt a csomagot. Új csomag telepítéséhez újra le kell futtatnunk a Cygwin telepítőjét.

Korlátozottan használható az FTP alkalmazások (pl. [WinSCP](http://winscp.net/)) beépített terminálja.

## Virtuális gépek elérése

Gyakran a virtuális gépeket is kényelmesebb SSH-n keresztül elérni. Ha egyszerre több gépet konfigurálunk, akkor érdemes olyan SSH klienst használni, ahol egyszerre adhatjuk ki a gépeknek ugyanazt a parancsot. Linuxon ilyen a `clusterssh` eszköz.

### SSH publikus kulcsok használata

A legegyszerűbb módja a felhasználók azonosításának a jelszó igénylése. Ez több szempontból [sem jó megoldás]([http://eev.ee/blog/2011/12/04/fuck-passwords/): körülményes mindig beírni a jelszót; ha csak néhány jelszót használunk, azt kockáztatjuk, hogy egy jelszóval a támadó több rendszerhez is hozzáfér; ha mindenhova más jelszót használunk, nem tudjuk megjegyezni őket és fel kell írnunk valahova.

A probléma megoldására nyújt megoldást a nyilvános kulcsú titkosításra építő [Diffie–Hellman kulcscsere](https://en.wikipedia.org/wiki/Diffie–Hellman_key_exchange). (Szintén nyílt kulcsú titkosítást alkalmaz az [RSA algoritmus](https://en.wikipedia.org/wiki/RSA_(cryptosystem) algoritmus.)

SSH kulcsokat használ a Git verziókezelő is ([GitHub tutorial](https://help.github.com/articles/generating-ssh-keys/)).

### Olvasnivalók

Leírás [SSH kulcsok generálásához](http://rcsg-gsir.imsb-dsgi.nrc-cnrc.gc.ca/documents/internet/node31.html).
