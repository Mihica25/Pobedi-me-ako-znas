# Slučaj upotrebe: Povezivanje na server
## Kratak opis:
Klikom na dugmad "Prikazi najbolje rezultate" ili "Pokreni igru", aplikacija pokusava da uspostavi konekciju sa serverom.
## Akteri:
/
## Preduslovi:
 /
## Postuslovi:
Ako je stisnuto dugme "Pokreni igru", klijentska aplikacija je povezana na server, klijent postaje vidljiv serveru i moze startovati partiju sa drugim klijentom.
Ako je stisnuto dugme "Najbolji rezultati", klijentska aplikacija je povezna na server i sprena da prihvati najbolje rezultate koje server treba poslati.
## Osnovni tok:
```
1. Klikom na dugmad "Prikazi najbolje rezultate" ili "Pokreni igru", aplikacija salje TCP zahtev serveru radi uspostavljanja konekcije.
2. Server prihvata zahtev za uspostavljanje konekcije.
3.TCP konekcija izmedju Klijenta i Servera je uspostavljena
    3.1. Ako je konekcija uspostavljena zbog igranja igre, klijent se dodaje u lobby (listu igraca koji cekaju na igru)
    3.2. Ako je konekcija uspostavljena zbog dohvatanja najboljih rezultata, server ucitava podatke, salje ih klijentu i zatvara TCP konekciju.

```
### Alternativni tokovi:

```
A1 – Nemogucnost ostvarivanja veze sa serverom. Pokusaj ostvarivanja veze se prekida i ceka se ponovni zahtev klijenta za uspostavu konekcije.

```

### Specijalni zahtevi:
 Klijenti moraju imati pristup internetu. Server aplikacije mora biti pokrenut i u stanju izvrsavanja u trenutku zahtevanja konekcije.

### Dodatne informacije:
/

