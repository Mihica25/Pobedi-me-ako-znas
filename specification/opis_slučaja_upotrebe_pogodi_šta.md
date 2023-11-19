# Slučaj upotrebe: Pogodi Šta
## Kratak opis
Igrači pokušavaju da pogode zamućenu zagonetnu sliku, pri čemu kako runde prolaze, slika postaje sve jasnija i jasnija, ali i tačan odgovor nosi manji broj poena. Igrači imaju pravo na jedan pokušaj po rundi, poene nosi onaj igrač koji pre pogodi pojam iza slike.

## Akteri:
- Igrači - Istovremeno pogadjaju zagonetni pojam slike

## Preduslovi
Partija je pokrenuta i otvoren je prozor za igru

## Postuslovi
Nakon što se igra završi, prelazi se na igru "Ko Zna" 
i podaci o zarađenim poenima se ažuriraju.

## Osnovni tok:
```
1. Aplikacija učitava prethodno osvojene poene
2. Aplikacija generiše zagonetnu sliku
3. Sve dok se ne pogodi pojam ili ne prodju sve runde.
    3.1 Aplikacija startuje tajmer runde
	3.2 Aplikacija otključava polje za unos odgovora
    3.3 Igrač unosi odgovor
    3.4 Aplikacija proverava da li je odgovor tačan
        3.4.1 Ako je odgovor tačan
            3.4.1.1 Aplikacija prikazuje tačan odgovor
            3.4.1.2 Aplikacija računa poene zavisno od runde u kojoj je pogodjeno rešenje
            3.4.1.3 Aplikacija ažurira poene
            3.4.1.4 Prelazi na slučaj upotrebe sledeće igre
        3.4.2 Ako je odgovor netačan
            3.4.2.1 Aplikacija zakljucava polje za unos odgovora i čeka da istekne runda ili da protivnik pogodi
                3.4.2.1.1 Ako je isteklo vreme runde
                    3.4.2.1.1.1 Prelazi na korak 3.4.3
                3.4.2.1.2 Ako je protivnik pogodio
                    3.4.2.1.2.1 Prelazi na korak 3.4.1 
        3.4.3 Ako je isteklo vreme runde
            3.4.3.1 Aplikacija olakšava sliku i ažurira vrednost pogodjenog odgovora
            3.4.3.2 Aplikacija restartuje tajmer runde
            3.4.3.3 Prelazi na korak 3.1
4. Ako su prosle sve runde i nije pogodjeno rešenje
    4.1 Aplikacija prikazuje tačan odgovor
    4.2 Prelazi na slučaj upotrebe "Ko Zna"

```

### Alternativni tokovi:
```
A1 - Neocekivani izlaz iz aplikacije. Ako u bilo kom trenutku korisnik isključi aplikaciju,
sve zapamćene informacije se poništavaju i aplikacija završava rad.
Slučaj upotrebe se završava.

A2 - Neočekivani izlaz protivnika iz aplikacije. Ako u bilo kom trenutku protivnik isključi
aplikaciju, sve zapamćene informacije se poništavaju i aplikacija prikazuje glavni meni.
Slučaj upotrebe se završava.

A3 - Neočekivani izlaz iz aplikacije. Ako u bilo kom trenutku se prekine konekcija sa serverom na bilo čijoj strani,
sve zapamćene informacije se poništavaju i aplikacija prikazuje glavni meni.
Slučaj upotrebe se završava.
```
### Podtokovi:
```
 /
 ```

### Specijalni zahtevi
Aplikacija i server su povezani međusobno.

### Dodatne informacija: 
```
D1 - Igra se sastoji iz dve partije (dve zagonetne slike) po 5 rundi

D2 - Svaka runda traje 12 sekundi (celokupna partija 60 sekundi) 

D3 - Pogodjeno rešenje nosi 25, 20, 15, 10, 5 poena po rundama 
```