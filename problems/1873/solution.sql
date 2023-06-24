# Write your MySQL query statement below
select
    employee_id, if(mod(employee_id, 2) > 0 and name not like 'M%', salary, 0) as bonus
from
    Employees
order by
    1 asc