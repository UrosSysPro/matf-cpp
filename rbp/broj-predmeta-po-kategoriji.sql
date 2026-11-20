select
    case
        when p.ESPB > 8 then 'tezak'
        when p.ESPB < 6 then 'lak'
        else 'srednje-tezak'
    end as kategorija,
    count(*) broj
from da.PREDMET p
group by (case
              when p.ESPB > 8 then 'tezak'
              when p.ESPB < 6 then 'lak'
              else 'srednje-tezak'
    end);

with pomocna_tabela as (
    select
        case
        when p.ESPB > 8 then 'tezak'
        when p.ESPB < 6 then 'lak'
        else 'srednje-tezak'
        end as kategorija
    from da.PREDMET p
    )
select i.kategorija, count(*)
from pomocna_tabela i
group by i.kategorija;
