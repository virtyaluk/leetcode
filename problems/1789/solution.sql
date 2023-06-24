with single as(
    select
        employee_id,
        department_id,
        count(*) as cnt
    from
        Employee
    group by
        employee_id
    having cnt = 1
),
multiple as(
    select
        employee_id,
        department_id
    from
        Employee
    where
        primary_flag = "Y"
)

SELECT
    employee_id,
    department_id 
FROM
    multiple
UNION
    SELECT
        employee_id,
        department_id
    FROM
        single