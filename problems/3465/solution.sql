# Write your MySQL query statement below
select
    *
from
    products
where
    description regexp 'SN[:digit:]{4}-[:digit:]{4}[^0-9]+'
    or
    description regexp 'SN[:digit:]{4}-[:digit:]{4}$'
order by
    1 asc