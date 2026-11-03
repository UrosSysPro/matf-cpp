
-- spajanje stringova
values ('Ime' || ' ' || 'Prezime', concat('hello', ' world'));

-- replace
values replace('hello aaa', 'aaa', 'world');

-- indeksi stringova
values substr('hello world',1,1) || ' ' || substr('hello world',7,1);

select
    header,
    case
        when header like 'hello %' then '+'
        else '-'
    end
from (values ('hello'), ('hello world'), ('pozdrav')) as  mytable(header);



-- ?. operator
select
    coalesce(null,'hello')
from (values ('a')) as mytable(hello);


values(char(current_date, EUR))

select * from
(
    values
        (1,'Grafika',6),
        (2,'Rbp',4),
        (3,'Kiaa',7),
        (4,'Mehanika',5),
        (5,'Ip2',7)
)
as Predmet(id, naziv, espb);

select
    id,
    naziv,
    decimal(espb*1.2, 6,2)
from
    (
        values
            (1,'Grafika',6),
            (2,'Rbp',4),
            (3,'Kiaa',7),
            (4,'Mehanika',5),
            (5,'Ip2',7)
    )
        as Predmet(id, naziv, espb);

select
    id,
    naziv,
    ceil(espb*1.2) "zaokruzeno"
from
    (
        values
            (1,'Grafika',6),
            (2,'Rbp',4),
            (3,'Kiaa',7),
            (4,'Mehanika',5),
            (5,'Ip2',7)
    ) as Predmet(id, naziv, espb)
where espb*1.2 > 8;

