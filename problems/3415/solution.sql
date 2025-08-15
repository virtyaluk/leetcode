# Write your MySQL query statement below
select
    *
from
    Products
where
    name regexp '[:digit:]{3}'
    and
    name not regexp '[:digit:]{4,}'
order by
    1