# Slučaj upotrebe: Čuvanje rezultata
## Kratak opis 
 Aplikacija nakon završene partije čuva informacije o igračima i postignutim poenima.
## Akteri:
/
## Preduslovi
 Igranje partije je uspešno završeno.

## Osnovni tok
```
1. Aplikacija šalje podatke serveru o igračima i postignutim poenima.
2. Server dohvata podatke.
3. Server čuva podatke u bazi.
4. Aplikacija prikazuje glavni meni igračima.
```
### Alternativni tokovi:
```
A1: Neocekivani izlaz iz aplikacije. Ukoliko u bilo kojem koraku korisnik isključi aplikaciju,
sve zapamćene informacije se poništavaju i aplikacija završava rad.
Slučaj upotrebe se završava.

```

### Specijalni zahtevi:
Veza izmedju aplikacije i servera je uspešno uspostavljena.
