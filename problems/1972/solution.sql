# Write your MySQL query statement below
with cte1 as (
    select
        caller_id as person1,
        recipient_id as person2,
        call_time
    from
        Calls
    union all
    select
        recipient_id as person1,
        caller_id as person2,
        call_time
    from
        Calls
),
cte2 as (
    select
        *,
        first_value(person2) over(partition by person1, date(call_time) order by call_time) as first_call_person,
        first_value(person2) over(partition by person1, date(call_time) order by call_time desc) as last_call_person
    from
        cte1
)

select
    distinct person1 as user_id
from
    cte2
where
    first_call_person = last_call_person