# Write your MySQL query statement below
select
    p.project_id,
    round(avg(e.experience_years), 2) as average_years
from
    Project p
left join
    Employee  e
on
    e.employee_id  = p.employee_id
group by
    p.project_id