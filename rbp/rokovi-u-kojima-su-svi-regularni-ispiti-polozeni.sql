select
    SKGODINA,
    OZNAKAROKA,
    count(*) broj_polozenih_ispita,
    count(distinct i.INDEKS) broj_studentata
from DA.ISPIT i
where i.SKGODINA = 2016
group by SKGODINA, OZNAKAROKA
having  min(OCENA) > 5

