# Write your MySQL query statement below
with cte as (
    select
        *,
        row_number() over(partition by city_id order by degree desc, day asc) as rn
    from
        Weather
)

select
    city_id,
    day,
    degree
from
    cte
where
    rn = 1
order by
    city_id asc