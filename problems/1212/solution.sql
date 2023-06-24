# Write your MySQL query statement below
with host_team as (
    select
        t.team_id,
        t.team_name,
        sum(
            case
                when m.host_goals > m.guest_goals then 3
                when m.host_goals = m.guest_goals then 1
                else 0
            end
        ) as points
    from
        Teams t
    left join
        Matches m
    on
        t.team_id = m.host_team
    group by
        t.team_id
),
guest_team as (
    select
        t.team_id,
        t.team_name,
        sum(
            case
                when m.guest_goals > m.host_goals then 3
                when m.guest_goals = m.host_goals then 1
                else 0
            end
        ) as points
    from
        Teams t
    left join
        Matches m
    on
        t.team_id = m.guest_team
    group by
        t.team_id
)

select
    h.team_id,
    h.team_name,
    h.points + g.points as num_points
from
    host_team h
join
    guest_team g
on
    h.team_id = g.team_iD
order by
    3 desc,
    1