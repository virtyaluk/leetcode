# Write your MySQL query statement below
with cte as (
    select
        company_id,
        max(salary) as max_salary
    from
        Salaries
    group by 1
)

select
    s.company_id,
    s.employee_id,
    s.employee_name,
    round(s.salary - (s.salary * (case
                        when cte1.max_salary < 1000 then 0
                        when cte1.max_salary > 10000 then 0.49
                        else 0.24
                     end))
         ) as salary
from
    Salaries s
join
    cte cte1
using (company_id)