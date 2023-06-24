# Write your MySQL query statement below
select
    c.country_name,
    (case
        when avg(w.weather_state) <= 15 then 'Cold'
        when avg(w.weather_state) >= 25 then 'Hot'
        else 'Warm'
    end) as weather_type
from
    Weather w
join
    Countries c
on
    w.country_id = c.country_id
    and
    month(w.day) = 11
group by
    w.country_id