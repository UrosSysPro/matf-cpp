```
Osvoji region

Data je binarna matrica Mn×m=(mij)
na kojoj je prikazana teritorija plavog i crvenog tima. Ukoliko je element mij

    0

, tada polje na poziciji (i,j)
okupira plavi tim;
1
, tada polje na poziciji (i,j)

    okupira crveni tim.

Ukoliko je neki region koji okupira plavi tim u potpunosti okružen poljima crvenog tima, onda taj region biva osvojen i njegova polja dodeljujemo crvenom timu. Drugim rečima, ukoliko region koji okupira plavi tim nema izlaz van granica matrice, onda on postaje crven.

Potrebno je promeniti i ispisati novu podelu teritorije.

Napomena: Povezanost polja posmatramo samo u četiri pravca (gore, dole, levo, i desno).
Opis ulaza

Sa standardnog ulaza se učitava dimenzija matrice n
i m, a nakon toga i elementi matrice Mn×m

.
Opis izlaza

Na standardni izlaz ispisati stanje matrice Mn×m

nakon što crveni tim osvoji sve moguće regione.
Primer
Ulaz

5 5
0 1 1 1 0
1 0 0 1 0
1 0 1 1 1
1 1 1 0 1
0 0 0 1 1

Izlaz

0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
1 1 1 1 1
0 0 0 1 1
```
