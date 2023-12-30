# Slučaj upotrebe: Igra "Memorija"

  

### Kratak opis:

U igri "Memorija" igrači okreću kartice i pokušavaju da pronađu sto više parova kartica. Za svaki pronađeni par igrač dobija po jedan poen.
  

### Akteri:

Dva igrača

### Preduslovi:

Završen je prethodni slučaj upotrebe, Igra "Pogodi Šta" .
  
### Postuslovi:

/

### Osnovni tok:

    1. Aplikacija učitava poene osvojene iz prethodnih igara.
    2. Prvi igrač je na potezu.
    3. Sve dok igrač koji je na potezu ne pronađe poslednji par kartica ponavljaju se naredni koraci:
      3.1. Igrač okreće dve različite kartice.
      3.2. Ako su slike na te dve kartice iste:
        3.2.1. Aplikacija uvecava broj poena tog igrača.
        3.2.2. Aplikacija obaveštava igrača koji nije na potezu o tekucem stanju
        3.2.3. Aplikacija se vraća na korak 3.1.
      3.3. Ukoliko su slike na te dve kartice različite:
        3.3.1. Aplikacija obaveštava oba igrača o tekućem stanju.
        3.3.2. Menjamo igrača koji je na potezu.
        3.3.3. Aplikacija se vraća na korak 3.1.
    4. Prelazimo na slučaj upotrebe "Čuvanje rezultata"
  

### Alternativni tokovi:

A1 - **Neočekivani izlaz iz aplikacije.** Ukoliko u bilo kojem koraku korisnik isključi aplikaciju,
sve zapamćene informacije se poništavaju i aplikacija završava rad.
Slučaj upotrebe se završava.

### Podtokovi:

/

### Specijalni zahtevi:

/
  

### Dodatne informacije:

DI1. Ukupan broj parova kartica je 20.
