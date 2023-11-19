# Slučaj upotrebe: Igra "My number"

  

### Kratak opis:

Igra "My number" se sastoji iz dve runde.  Za svaku rundu, aplikacija generiše jedan (traženi) broj 1-999, potom četiri jednocifrena (brojevi 1-9) i dva dvocifrena broja (brojeve 10,  15, 25, 50 ili 75). Koristeći operacije +, -, * i / igrači treba da dobiju što približnije rešenje traženom broju.
  

### Akteri:

Igrači

### Preduslovi:

Završen je prethodni slučaj upotrebe, Igra _____ .
  
### Postuslovi:

Rezultati partije igre "My number" se čuvaju. Prelazi se na slučaj upotrebe Igru ______.

### Osnovni tok:

    1. Prva runda igre započinje.
    2. Aplikacija generiše traženi broj i pomoćne brojeve za njegovo izračunavanje.
    3. Aplikacija konstruiše novi tajmer i njegovo odbrojavanje započinje.
    4. Sve dok ne istekne vreme ili oba igrača ne predaju svoje postupke ponavlja se naredni korak:
      4.1. Igrači formiraju svoje rešenje (postupak).
    5. Aplikacija proverava validnost odgovora.
      5.1. Postupak rešavanja oba igrača je ispravan
        5.1.1.  Aplikacija izračunava rešenja postupaka.
        5.1.2.  Ukoliko su oba igrača pronašla broj iste udaljenosti u odnosu na traženi
            5.1.2.1.  Aplikacija dodeljuje poene bržem igraču
            5.1.2.2.  Prelazi se na korak 6.
        5.1.3.  Ukoliko podtoji igrač koji je pronašao broj na manjoj udaljenosti u odnosu na traženi
            5.1.3.1.  Aplikacija dodeljuje poene tom igraču
            5.1.3.2.  Prelazi se na korak 6.
      5.2. Postupak rešavanja oba igrača je neispravan
        5.2.1. Aplikacija ne dodeljuje poene nijednom igraču.
        5.2.2. Prelazi se na korak 6.
      5.3. Postupak rešavanja jednog igrača je neispravan, a drugog ispravan
        5.3.1. Aplikacija dodeljuje odgovarajući broj poena igraču sa ispravnim postupkom.
        5.3.2. Prelazi se na korak 6.
    6. Aplikacija provera koja je runda odigrana.
      6.1. Ukoliko je završena prva runda
        6.1.1. Prelazi se na korak 2.
      6.2. Ukoliko je završena druga runda
        6.2.1. Prelazi se na korak 7.
    7. Prelazi se na slučaj upotrebe _____.
  

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

Postoji konekcija aplikacije sa serverom tokom trajanja igre.
  

### Dodatne informacije:

DI1.  Postoje dve runde igre.

DI2. Vremensko ograničenje jedne runde je 60s.

DI3. Broj poena koji se dodeljuje igraču koji je pobedio u rundi je 10.

DI4. Postupak se smatra neispravnim ukoliko ne postoji ili se javlja ???? greška.
