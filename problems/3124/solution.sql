# Write your MySQL query statement below
with inc as (select
    b.first_name as first_name,
    a.type as type,
    CONCAT(
        LPAD(FLOOR(a.duration / 3600), 2, '0'), ':',
        LPAD(FLOOR((a.duration % 3600) / 60), 2, '0'), ':',
        LPAD(FLOOR(a.duration % 60), 2, '0')
    ) AS duration_formatted
from
    Calls a
left join
    Contacts b
on
    a.contact_id = b.id
where
    a.type = 'incoming'
order by
    a.duration desc
limit
    3
),
outg as (select
    b.first_name as first_name,
    a.type as type,
    CONCAT(
        LPAD(FLOOR(a.duration / 3600), 2, '0'), ':',
        LPAD(FLOOR((a.duration % 3600) / 60), 2, '0'), ':',
        LPAD(FLOOR(a.duration % 60), 2, '0')
    ) AS duration_formatted
from
    Calls a
left join
    Contacts b
on
    a.contact_id = b.id
where
    a.type = 'outgoing'
order by
    a.duration desc
limit
    3
)

select * from inc
union
select * from outg