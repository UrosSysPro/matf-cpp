# Suma raspona preko prefiksnih suma

Neka je dat niz celih brojeva a
dužine n. 
Postoje dva tipa upita:
u i x

koji na poziciju i postavlja vrednost x
;
slr
koji računa ∑ri=lai

    .

Opis ulaza

Sa standardnog ulaza se unose celi brojevi n
i q, a zatim i n elemenata niz a. Nakon toga unosi se q upita. Svaki upit j=1,…,q čini tip upita tj∈{u,s} i argumenti. Ukoliko je tip upita tj=u, argumenti upita j su indeks ij (0≤ij<n) i vrednost xj, a ukoliko je tip upita tj=s, argumenti upita j su indeksi lj i rj (0≤lj≤rj<n

). Pretpostaviti da je broj upita prvog tipa mnogo manji od broja upita drugog tipa.
Opis izlaza

Za svaki upit drugog tipa ispisati traženu sumu.
Primer
```
Ulaz

8 4
3 1 4 1 5 9 2 6
s 1 3
s 0 4
u 1 4
s 0 4

Izlaz

6
14
17
```