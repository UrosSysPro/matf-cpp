select
    p.ID,
    p.NAZIV,
    p.OZNAKA,
    count(distinct  i.INDEKS) as broj
from
    DA.PREDMET p left join da.ISPIT i
    on p.ID = i.IDPREDMETA and i.OCENA > 5
where p.NAZIV like 'P%'
group by p.ID, p.NAZIV, p.OZNAKA
-- having avg(i.OCENA) > 2  primer koriscenja having
order by  broj;