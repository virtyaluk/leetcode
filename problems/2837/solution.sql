# Write your MySQL query statement below
with cte as (
    select
        user_id,
        sum(distance) distance
    from
        Rides
    group by
        user_id
)

select
    u.user_id,
    u.name,
    if(isnull(cte1.distance), 0, cte1.distance) as 'traveled distance'
from
    Users u
left join
    cte cte1
on
    u.user_id = cte1.user_id
order by
    u.user_id
