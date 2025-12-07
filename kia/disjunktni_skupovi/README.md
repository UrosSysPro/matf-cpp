```
Disjunktni skupovi implementirani preko povezane liste

Struktura podataka disjunktnih skupova održava kolekciju S={S1,S2,…,Sk}
disjunktnih dinamičkih skupova. Svaki skup se identifikuje nekim svojim elementom, koga nazivamo predstavnik. Neka x i y

označava neke objekate, želimo da struktura disjunktnih skupova podržava sledeće operacije:

    make_set(x)

kreira novi skup čiji je jedini element x. Kako su skupovi koje održavamo disjunktni, zahtevamo da x
ne pripada nekom drugom skupu;
union(x,y)
izvršava operaciju unije nad skupovima koji sadrže elemente x i y
;
find_set(x)
vraća pokazivač na predstavnika skupa kome x

    pripada.

Koristeći povezane liste implementirati strukturu disjunktnih skupova koja podržava sve tri operacije. Analizirati složenost svake operacije.
Opis ulaza

/
Opis izlaza

/
Rešenje
```
