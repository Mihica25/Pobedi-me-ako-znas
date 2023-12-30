# Slučaj upotrebe: Igra "Rečko"

  

### Kratak opis:

Igrač započinje jednu partiju igre. Ima 5 pokušaja da pogodi koja je tajna reč od 5 slova, pri čemu dobija povratnu informaciju o pogođenim slovima bilo da su na pravom ili pogrešnom mestu.
  

### Akteri:

Igrači - svaki igrač igra po jednu partiju igre

### Preduslovi:

Započet je niz igara.
  
### Postuslovi:

Prelazi se na slučaj upotrebe Igru "Moj broj".

### Osnovni tok:

    1. Prva runda igre započinje.
    2. Aplikacija prikazuje 6 vrsta po 5 kvadratića.
    3. Aplikacija konstruiše novi tajmer i njegovo odbrojavanje započinje.
    4. Sve dok ne istekne vreme ili se ne iskoristi 5 pokušaja, ponavaljaju se koraci:
        4.1. Igrač unosi reč od 5 slova.
        4.2. Aplikacija proverava da li ima pogođenih slova
            4.2.1. Dok ne završi poslednje slovo, ponavljaju se koraci:
                4.2.1.1. Ako trenutno slovo postoji u tajnoj reči ali na drugom mestu, potrebno je obavestiti igrača
                    4.2.1.1.1. Aplikacija boji trenutni kvadratić u žuto.
                4.2.1.2. Ako trenutno slovo postoji u tajnoj reči baš na tom mestu, potrebno je obavestiti igrača
                    4.2.1.2.1. Aplikacija boji taj kvadratić u zeleno.
        4.3. Ako je pronađena tajna reč, igra je gotova
            4.3.1. Aplikacija ispisuje obaveštenje da je reč uspešno otkrivena.
            4.3.2. Prelazi se na korak 6.
    5. Aplikacija ispisuje obaveštenje da reč nije otkrivena.
    6. Aplikacija ispisuje klijentima tačnu reč.
    7. Aplikacija proverava koja se runda završila
        7.1. Ako se završila prva onda se prelazi na korak 2.
        7.2. Ako se završila druga runda onda se prelazi na slučaj upotrebe "Moj broj".
  

### Alternativni tokovi:

A1 - **Neočekivani izlaz iz aplikacije.** Ukoliko u bilo kojem koraku korisnik isključi aplikaciju,
sve zapamćene informacije se poništavaju i aplikacija završava rad.
Slučaj upotrebe se završava.

A2 - **Neočekivani izlaz protivnika iz aplikacije.** Ukoliko u bilo kojem koraku protivnik isključi
aplikaciju, sve zapamćene informacije se poništavaju i aplikacija prikazuje glavni meni.
Slučaj upotrebe se završava.


### Podtokovi:

/

### Specijalni zahtevi:

/
  

### Dodatne informacije:

DI1. Postoje dve runde igre.

DI2. Vremensko ograničenje jedne runde je 60s.



