# Slučaj upotrebe: Igra "Ko zna"

  

### Kratak opis:

Kratak opis: Igrači započinju jednu partiju igre. Dobijaju pitanje i 4 ponuđena odgovora od kojih je 1 tačan. Poene dobija onaj igrač koji odgovori tačno na pitanje. Ukoliko i on i protivnik odgovore tačno, dobijaju podrundu, odnosno pitanje čiji je odgovor određeni broj. Onaj igrač koji je bio bliži rešenju dobija poene.

  

### Akteri:

Igrači

### Preduslovi:

Završen je prethodni slučaj upotrebe, Igra "Pogodi šta" .
  
### Postuslovi:

Rezultati partije igre "Ko zna" se obračunavaju. Prelazi se na slučaj upotrebe igru "Memorija".

### Osnovni tok:

    1. Prva runda igre započinje.
    2. Dok ne prođu sva pitanja, ponvljaju se sledeći koraci:
        2.1. Aplikacija prikazuje pitanje sa 4 ponuđena odgovora
        2.2. Aplikacija konstruiše tajmer i započinje odbrojavanje
        2.3. Igrači imaju priliku do kraja isteka vremena na tajmeru da odgovore na pitanje
        2.4. Aplikacija dodeljuje poene u odnosu na odgovore igrača
            2.4.1. Ukoliko je samo jedan igrač odgovorio tačno na pitanje, dodeljuju mu se poeni
            2.4.2. Ukoliko su neki ili oba igraca dali pogrešan odgovor, dobijaju kaznene poene
            2.4.3. Ukoliko su oba igrača odgovorila tačno na pitanje
	            2.4.3.1. Aplikacija otvara podrundu - pitanje
                2.4.3.2. Aplikacija konstruiše novi tajmer i započinje odbrojavanje
                2.4.3.3. Igrači unose broj
                2.4.3.4. Aplikacija dodeljuje poene u odnosu na odgovore igrača
                    2.4.3.4.1. Ukoliko je jedan igrač bio bliži odogovoru, dodeljuju mu se poeni
                    2.4.3.4.2. Ukoliko su rešenja oba igrača jednako udaljena od tačnog odgovora, poeni se dodeljuju bržem
                2.4.3.5 Prikazuje se tačan odogovor iz podrunde i prelazi na korak 3
        2.5. Prikazuje se tačan odgovor
    3. Prelazi se na slučaj upotrebe „Čuvanje rezultata”
    4. Aplikacija prelazi na igru "Memorija"
  
    

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

/
