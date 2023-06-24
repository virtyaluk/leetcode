# Write your MySQL query statement below
with cte as (
    select Wimbledon as id from Championships
    union all
    select Fr_open as id from Championships
    union all
    select US_open as id from Championships
    union all
    select Au_open as id from Championships
)

select
    p.player_id,
    p.player_name,
    count(c.id) as grand_slams_count
from
    Players p
join
    cte c
on
    p.player_id = c.id
group by
    p.player_id, p.player_name