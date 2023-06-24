# Write your MySQL query statement below
select
    e2.employee_id,
    e2.name,
    count(e1.name) as reports_count,
    round(avg(e1.age)) as average_age
from
    Employees e1
join
    Employees e2
on
    e1.reports_to = e2.employee_id
group by
    e1.reports_to
order by 1