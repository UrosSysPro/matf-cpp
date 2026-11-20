select
    i.IDPREDMETA,
    count(distinct i.INDEKS) BROJ_STUDENTATA
from DA.ISPIT i
group by i.IDPREDMETA
having count(distinct i.INDEKS) > 50
order by BROJ_STUDENTATA desc