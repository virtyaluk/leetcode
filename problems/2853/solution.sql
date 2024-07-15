# Write your MySQL query statement below
with cte1 as (
    select
        max(salary) as salary,
        '1' as id
    from
        Salaries
    where
        department = 'Engineering'
    group by
        department
    
),
cte2 as (
    select
        max(salary) as salary,
        '1' as id
    from
        Salaries
    where
        department = 'Marketing'
    group by
        department
)

select
    abs(e.salary - m.salary) as salary_difference
from
    cte1 e
left join
    cte2 m
on e.id = m.id