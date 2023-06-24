# Write your MySQL query statement below
with countries as (
    select
        c.name as country,
        avg(ca.duration) as avg_duration
    from
        Person p
    join
        Country c
    on
        c.country_code = substring(p.phone_number, 1, 3)
    inner join
        Calls ca
    on
        p.id in (ca.caller_id, ca.callee_id)
    group by
        c.name
)

select
    country
from
    countries
where
    avg_duration > (select avg(duration) from Calls)