# Write your MySQL query statement below
select
    state,
    group_concat(city order by city asc separator ', ') as cities
from
    cities
group by
    1
order by
    1 asc