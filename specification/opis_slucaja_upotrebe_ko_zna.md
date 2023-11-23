# Slučaj upotrebe: Igra "Ko zna"

  

### Kratak opis:

Kratak opis: Igrači započinju jednu partiju igre. Dobijaju pitanje i 4 ponuđena odgovora od kojih je 1 tačan. Poene dobija onaj igrač koji odgovori tačno na pitanje. Ukoliko i on i protivnik odgovore tačno, dobijaju podrundu, odnosno pitanje čiji je odgovor određeni broj. Onaj igrač koji je bio bliži rešenju dobija poene.

  

### Akteri:

Igrač1 – igra jednu partiju igre
Igrač2 – igra istu tu partiju igre

### Preduslovi:

Završen je prethodni slučaj upotrebe, Igra "Pogodi šta" .
  
### Postuslovi:

Rezultati partije igre "Ko zna" se obračunavaju. Prelazi se na slučaj upotrebe igru "Memorija".

### Osnovni tok:

    1. Prva runda igre započinje.
    2. Dok ne prođu sva pitanja, ponvljaju se sledeći koraci:
        2.1. Aplikacija prikazuje pitanje sa 4 ponuđena odgovora
        2.2. Aplikacija konstruiše tajmer i započinje odbrojavanje
        2.3. Igrač1 odgovara na pitanje
        2.4. Igrač2 odgovara na pitanje
        2.5. Aplikacija proverava da li je isteklo vreme
            2.5.1. Aplikacija proverava da li je Igrač1 odgovorio tačno, a Igrač2 nije
                2.5.1.1. Igrač1 dobija poene
                2.5.1.2. Igrač2 dobija kaznene poene
	            2.5.1.3. Prelazi se na korak 2.1.
            2.5.2. Aplikacija proverava da li je Igrač2 odgovorio tačno, a Igrač1 nije
                2.5.2.1. Igrač1 dobija kaznene poene
	            2.5.2.2. Igrač2 dobija poene
	            2.5.2.3. Prelazi se na korak 2.1.
            2.5.3. Aplikacija proverava da li su oba igrača odgovorila tačno
                2.5.3.1. Aplikacija otvara podrundu - pitanje
                2.5.3.2. Aplikacija konstruiše tajmer1 i započinje odbrojavanje
                2.5.3.3. Aplikacija konstruiše tajmer2 i započinje odbrojavanje
                2.5.3.4. Igrač1 unosi broj
                2.5.3.5. Igrač2 unosi broj
`               2.5.3.6. Aplikacija proverava da li je isteklo vreme
                    2.5.3.6.1. Aplikacija proverava da li je Igrač1 bio bliži
                        2.5.3.6.1.1. Igrač1 dobija poene
	    	            2.5.3.6.1.2. Prelazi se na korak 2.1.
                    2.5.3.6.2. Aplikacija proverava da li je Igrač2 bio bliži
                        2.5.3.6.2.1. Igrač2 dobija poene
	    	            2.5.3.6.2.2. Prelazi se na korak 2.1.
                    2.5.3.6.3. Aplikacija proverava da li su rešenja oba igrača jednako udaljena od tačnog rešenja
                        2.5.3.6.3.1. Aplikacija proverava da li je Igrač1 brže odgovorio
                            2.5.3.6.3.1.1. Igrač1 dobija poene
	    	    	        2.5.3.6.3.1.2. Prelazi se na korak 2.1.
                        2.5.3.6.3.2. Aplikacija proverava da li je Igrač2 brže odgovorio
                            2.5.3.6.3.2.1. Igrač2 dobija poene
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
