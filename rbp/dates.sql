values (
           dayofyear(current_date),
           week(current_date),
           dayofweek(current_date),
           dayname(current_date),
           monthname(current_date)
       );

values
    dayofyear(current_date),
    week(current_date),
    dayofweek(current_date);

values (current_time, hour(current_time), minute(current_time ), second(current_date));

-- int u formatu yyyymmdd?????
values date('11.11.2008') - date('6.8.2005');


-- radi
values days_between('11.11.2008','6.8.2005');
values days('11.11.2008') - days('6.8.2005');

-- koji ce datum biti za 12 godina, pet meseci i 22 dana
values current_date + 12 years  + 5 months + 22 days;
