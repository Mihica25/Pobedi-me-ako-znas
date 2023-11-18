# Slučaj upotrebe: Povezivanje na server
## Kratak opis:
Prilikom pokretanja klijentskog dela aplikacije, nakon prikazivanja glavnog menija, aplikacija pokusava da uspostavi konekciju sa serverom.
## Akteri:
/
## Preduslovi:
 /
## Postuslovi:
 Klijentska aplikacija je povezana na server, klijent postaje vidljiv serveru i moze startovati partiju sa drugim klijentom.
## Osnovni tok:
```
1. Prilikom pokretanja klijentske aplikacije, aplikacija salje TCP zahtev serveru radi uspostavljanja konekcije.
2. Server prihvata zahtev za uspostavljanje konekcije i dodaje klijenta u listu onlajn klijenata.
3. TCP konekcija izmedju Klijenta i Servera je uspostavljena.

```
### Alternativni tokovi:

```
A1 – Nemogucnost ostvarivanja veze sa serverom. Klijentska aplikacija pokusava automatski ponovo da uspostavi vezu.

```

### Specijalni zahtevi:
 Klijenti moraju imati pristup internetu. Server aplikacije mora biti pokrenut i u stanju izvrsavanja u trenutku zahtevanja konekcije.

### Dodatne informacije:
/

