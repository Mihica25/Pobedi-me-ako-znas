# Slučaj upotrebe: Prikazivanje najboljih rezultata

## Kratak opis: 
Igrač iz glavnog menija bira opciju za prikazivanje najboljih rezultata.
Aplikacija prikazuje najbolje rezultate na ekranu.

## Akteri: 
Igrač

## Preduslovi: 
Aplikacija je pokrenuta i prikazuje glavni meni.

## Postuslovi: 
Informacije o najboljim rezultatima su prikazane na ekranu.

## Osnovni tok:

	1. Igrač bira dugme "Najbolji rezultati" iz glavnog menija.

	2. Aplikacija salje zahtev za podatke serveru.
    
    3. Server prima zahtev, dohvata podatke iz baze i šalje ih Aplikaciji.

    4. Aplikacija prima podatke i prikazuje ih Igraču na ekranu.

	3. Igrač bira dugme za povratak u glavni meni.

	4. Aplikacija prikazuje glavni meni.

### Alternativni tokovi: 
A1: Neočekivani izlazak iz aplikacije. Ukoliko u bilo kojem koraku korisnik isključi aplikaciju, sve informacije o rezultatima ostaju upamćene. Aplikacija završava rad.
Slučaj upotrebe se završava.

### Podtokovi: 
/

### Specijalni uslovi: 
Konekcija sa serverom je uspešno uspostavljena.

### Dodatne informacije: 
/
