select
    i.INDEKS,
    d.IME || ' ' || d.PREZIME,
    monthname(i.DATPOLAGANJA) as mesec,
    count(*)
from DA.ISPIT i left join da.DOSIJE d on i.INDEKS = d.INDEKS
where i.OCENA > 5
group by i.INDEKS, monthname(i.DATPOLAGANJA), d.ime, d.prezime
having count(*) > 2
order by i.INDEKS, mesec