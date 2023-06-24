# Write your MySQL query statement below
select
    c.seat_id
from
    Cinema c
where
    c.free = 1
    and
    0 < (select count(*) from Cinema where free = 1 and (seat_id = c.seat_id - 1 or seat_id = c.seat_id + 1))
order by
    1 asc