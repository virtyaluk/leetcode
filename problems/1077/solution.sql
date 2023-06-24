# Write your MySQL query statement below
select
    p.project_id,
    p.employee_id
from
    Project p
join
    Employee e
on
    p.employee_id = e.employee_id
where
    (p.project_id, e.experience_years) in (
        select
            project_id,
            max(experience_years)
        from
            Employee
        join
            Project
        using (employee_id)
        group by project_id
    )