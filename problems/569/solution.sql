# Write your MySQL query statement below
with cte1 as (
    select
        *,
        row_number() over(partition by company order by salary asc) as rn
    from
        Employee
),
cte2 as (
    select
        company,
        count(company) as cnt
    from
        Employee
    group by
        company
)

select
    a.id,
    a.company,
    a.salary
from
    cte1 a
join
    cte2 b
on
    a.company = b.company
    and
    a.rn >= b.cnt / 2
    and a.rn <= b.cnt / 2 + 1