# Write your MySQL query statement below
select
    team_id,
    team_name,
    wins * 3 + draws as points,
    rank() over(order by wins * 3 + draws desc) as position
from
    TeamStats
order by
    3 desc,
    2