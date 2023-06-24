# Write your MySQL query statement below
with cte1 as (
    select
        id,
        login_date,
        row_number() over(partition by id order by login_date asc) as rn
    from
        Logins
    group by
        1, 2
),
cte2 as (
    select
        id,
        date_sub(login_date, interval rn day) as rn2
    from
        cte1
    group by
        1, 2
    having
        count(id) >= 5
)

select
    a.id,
    b.name
from
    cte2 a
left join
    Accounts b
on
    a.id = b.id
group by
    1, 2