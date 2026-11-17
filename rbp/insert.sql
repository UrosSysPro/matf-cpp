insert
into da.PREDMET(
    ID, OZNAKA, NAZIV, ESPB
)
values
(4005, 'r103','Razvoj Softvera', 6)
;

select * from da.PREDMET where id=4005;

select * from da.USLOVNIPREDMET;

select * from da.PREDMET;


with ime_i_pozicija (indeks, ime, pozicija) as (
    select indeks, ime, 1 from da.DOSIJE
    union all
    select indeks, ime, pozicija +1 from ime_i_pozicija
    where pozicija < length(ime)
)
select * from ime_i_pozicija
where substr(lower(ime), pozicija, 1) = 'a'
order by indeks, ime;