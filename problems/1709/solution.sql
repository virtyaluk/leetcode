# Write your MySQL query statement below
with cte1 as (
    select
        *,
        lead(visit_date, 1, '2021-1-1') over(partition by user_id order by visit_date) as lead_date
    from
        UserVisits
),
    cte2 as (
        select
            user_id,
            datediff(lead_date, visit_date) as win
        from
            cte1
)

select
    user_id,
    max(win) as biggest_window
from
    cte2
group by
    user_id
order by
    user_id asc