# Write your MySQL query statement below
with all_emp as (
    select
        employee_id,
        experience,
        sum(salary) over(partition by experience order by salary) as running_salary
    from
        Candidates
)

select
    employee_id
from
    all_emp
where
    experience = 'Senior'
    and
    running_salary <= 70000
union
select
    employee_id
from
    all_emp
where
    experience = 'Junior'
    and
    running_salary <= (70000 - (
        select
            ifnull(max(running_salary), 0)
        from
            all_emp
        where
            experience = 'Senior' and running_salary <= 70000
    ))