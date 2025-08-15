# Write your MySQL query statement below
with cte as (
    select
        emp_id,
        salary,
        dept,
        dense_rank() over(partition by dept order by salary desc) as salary_rank
    from
        employees
)

select
    emp_id,
    dept
from
    cte
where
    salary_rank = 2
order by
    1